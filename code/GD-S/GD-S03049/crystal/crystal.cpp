#include<bits/stdc++.h>
using namespace std;
const int SIZ=5e5+5;
int n,ans,res=1,l=1;
long long a[SIZ],m,nd=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;)
	{
		while(nd>m)
		{
			nd-=abs(a[i]-a[l]);
			res--;l++;
		}
		ans=max(res,ans);
		i++;
		nd+=(a[i]-a[i-1])*(res);
		res++;
	}
	cout<<ans;
}
