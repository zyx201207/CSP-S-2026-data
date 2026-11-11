#include<bits/stdc++.h>
using namespace std;
int n , k , a[500005] , m[300005] ,f[300005] , s[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	int x = 0,l;
	while(n--){
		cin>>l;
		if(l!=a[x]){
			a[++x]=l;
			m[a[x]]++;
			if(!f[a[x]])f[a[x]]=x;
		}
	}
	n=x;
	for(int i = n;i >= 1;i--){
		if(!s[a[i]])s[a[i]]=i;
	}	
	for(int i = n;i >= 1;i--){
		for(int j = i;j >= 1;j--){
			if(s[a[j]]>i and i!=j){
				ans[a[i]]=max(ans[a[i]],j-1);
				break;
			}
			if(j==1)ans[a[i]]=max(ans[a[i]],i);
		}
		ans[a[i]]=max(ans[a[i]],1);
	}
	for(int i = 1;i <= k;i++)cout<<ans[i]<<" ";
	return 0;
}
