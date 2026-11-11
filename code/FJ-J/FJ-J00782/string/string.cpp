#include<bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005],ant[200005],cnt[200005];
long long l,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		cnt[i]=l+1;
		l=l+a[i];
		ant[i]=l;
	}
	int sum=1,num=n,ans=0;
	for(int i=1;i<=l/2+1;i++){
		if(ant[sum]<i) sum++;
		if(cnt[num]>l-i+1) num--;
    	if(c[sum]!=c[num]){
    		ans++;
   		} 
	}
	cout<<ans;
	return 0;
}
