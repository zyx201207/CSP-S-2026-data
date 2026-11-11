#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
long long ans;
char ch[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>ch[i];
	int l=1,r=n;
	while(l<r){
		if(ch[l]==ch[r]){
			l++,r--;
			continue;
		}
		if(a[l]>a[r]){
			ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else{
			ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--;
	}
	cout<<ans;
	return 0;
}
