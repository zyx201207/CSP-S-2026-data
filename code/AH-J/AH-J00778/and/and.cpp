#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[200005];
long long ans;
int z;
string f(long long a)
{
	string ss;
	int xx=0;
	while(a)
	{
		ss=ss+char(a%2+'0');
		a/=2;
		xx++;
	}
	z=max(z,xx);
	return ss;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		s[i]=f(x);
		//~ cout<<s[i]<<" "<<s[i][2]<<'\n';
	}
	for(int j=z-1;j>=0;j--)
	{
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			cnt+=(s[i][j]=='1');
		}
		if(cnt>=m)
		{
			cnt=1;
			for(int i=1;i<=n;i++)
			{
				if(s[i][j]=='1')
				{
					s[cnt++]=s[i];
				}
			}
			n=cnt-1;
			ans+=(1<<j);
		}
	}
	cout<<ans;
	return 0;
}
