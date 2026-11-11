#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>x[i];
		int w=1,jl1=1,jl2=1,ans=0;
		while(x[w]+d<x[n])
		{
			for(jl1;;jl1++)
			{
				if(x[w]+d<x[jl1])
				break;
			}
			jl1--;
			int p=jl1-1,q=jl1-2;
			if(q>0)
			{
				for(jl2=max(jl2,jl1+1);;jl2++)
				{
					if(x[jl2]-d<=x[p]&&x[jl2]-d>x[q])
					ans++;
					if(x[jl2]-d>x[p]||jl2>n)
					break;
				}
				jl2--;
			}
			w++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
