#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(m==2)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(n<=20)
	{
		if(m==3)
		{
			for(int A=1;A<=n-2;A++)
				for(int B=A+1;B<=n-1;B++)
					for(int C=B+1;C<=n;C++)
						ans=max(ans,a[A]&a[B]&a[C]);
		}
		if(m==4)
		{
			for(int A=1;A<=n-3;A++)
				for(int B=A+1;B<=n-2;B++)
					for(int C=B+1;C<=n-1;C++)
						for(int D=C+1;D<=n;D++)
							ans=max(ans,a[A]&a[B]&a[C]&a[D]);
		}
		if(m==5)
		{
			for(int A=1;A<=n-4;A++)
				for(int B=A+1;B<=n-3;B++)
					for(int C=B+1;C<=n-2;C++)
						for(int D=C+1;D<=n-1;D++)
							for(int E=D+1;E<=n;E++)
								ans=max(ans,a[A]&a[B]&a[C]&a[D]&a[E]);
		}
		if(m==6)
		{
			for(int A=1;A<=n-5;A++)
				for(int B=A+1;B<=n-4;B++)
					for(int C=B+1;C<=n-3;C++)
						for(int D=C+1;D<=n-2;D++)
							for(int E=D+1;E<=n-1;E++)
								for(int F=E+1;F<=n;F++)
									ans=max(ans,a[A]&a[B]&a[C]&a[D]&a[E]&a[F]);
		}
		if(m==7)
		{
			for(int A=1;A<=n-6;A++)
				for(int B=A+1;B<=n-5;B++)
					for(int C=B+1;C<=n-4;C++)
						for(int D=C+1;D<=n-3;D++)
							for(int E=D+1;E<=n-2;E++)
								for(int F=E+1;F<=n-1;F++)
									for(int G=F+1;G<=n;G++)
										ans=max(ans,a[A]&a[B]&a[C]&a[D]&a[E]&a[F]&a[G]);
		}
		cout<<ans;
	}
	return 0;
}
