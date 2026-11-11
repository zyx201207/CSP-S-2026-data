#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[(int)5e5+10],sum[(int)5e5+10],cnt[(int)5e5+10];
int n,m,ans;
int f(int l,int r)//zheyiduande m 
{
	return (r-l+1)*a[l-1]-sum[r]+sum[l-1];
}
int find(int l,int r){
	while(f(l,r)>m){
		//cout<<l<<' '<<r<<' '<<f(l,r)<<'\n';
		r=(l+r)/2;
	}
	while(1){
		if(f(l,r+1)>m||r>=n) break;
		//cout<<f(l,r)<<'\n';
		r++;
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<ll>());
	if(n>5000)
	{
		long long gc=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if((gc+gc*(i-1))*(i-1)/2>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]+=a[i]+sum[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		int aw=find(i+1,n)-i+1;
		ans=max(ans,aw);
	}
	cout<<ans;
	return 0;
}
