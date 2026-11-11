#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+100;
long long n,m,a[N],s[N];
long long res=-0x3f3f3f,ans,x=1,cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt+=a[i];
	}
	if(cnt==(a[1]+a[n])*n/2)
	{
		int aa=1;
		while(m>0)
		{
			aa++;
			m-=aa;
		}
		cout<<aa-1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		s[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		if(s[i]!=0)
		{
			if(ans+s[i]*x<=m)
			{
				ans+=s[i]*x;
			}
			else
			{
				res=max(res,(m-ans)/s[i]);
				res=max(res,x);
				x=1;ans=0;
			}
		}
		x++;
	}
	cout<<res<<endl;
}