#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=0,res,counts=0;
int wanna;
ll a[500005],b[500005];
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
res=m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
sort(a+1,a+1+n);
for(int j=1;j<=n;j++)
{
	counts=0;
	res=m;
	wanna=j;
	for(int i=wanna;i>=1;i--)
	{
		int k=a[wanna]-a[i];
		res-=k;
		if(res<0) break;
		counts++;
	}
	ans=max(ans,counts);
}
	cout<<ans;
return 0;	
} 
