#include <bits/stdc++.h>
using namespace std;
int c,t,n,l[1000005],r[1000005],tot,bl[1000005],br[1000005];
long long d,x[2000005],ans;
bool b[2000005],bb[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int ll=1;ll<=t;ll++)
	{
		cin>>n>>d;
		ans=0;tot=0;
		for(int i=1;i<=n;i++)
		{
			b[i]=false;
			bb[i]=false;
			cin>>x[i];
		}
		if(n<4)
		{
			cout<<"0\n";
			continue;
		}
		if(x[n]-x[1]<=d)
		{
			cout<<"0\n";
			continue;
		}
		if(c==11&&c==12)
		{
			if(x[3]-x[1]<=d)
			{
				cout<<n-3<<"\n";
			}
			else cout<<"0\n";
		}
		else if(c==13&&c==14)
		{
			cout<<"0\n";
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(i>=4&&x[i]-x[i-2]<=d&&x[i-1]-x[i-3]<=d)
				{
					if((((i+1>n||x[i+1]-x[i-2]>d)&&(i-4<1||x[i-1]-x[i-4]>d))||(x[i]-x[i-3]>d)))
					{
						l[++tot]=i-3;
						r[tot]=i;
					}
				}
				if(i>=3&&x[i]-x[i-2]<=d)
				{
					b[i-2]=true;
				}
				if(i>=2&&x[i]-x[i-1]>d)
				{
					bb[i]=true;
				}
			}
			for(int i=1;i<=n;i++)
			{
				bl[i]=bl[i-1];
				//if(b[i-1])bl[i]=i-1;
				if(bb[i])bl[i]=i-1;
			}
			br[n+1]=n+1;
			r[tot+1]=n+1;
			for(int i=n;i>=1;i--)
			{
				br[i]=br[i+1];
				//if(b[i-1])br[i]=i+1;
				if(bb[i+2])br[i]=i+1;
			}
			for(int i=1;i<=tot;i++)
			{
				ans+=(l[i]-max(bl[l[i]],l[i-1]))*(min(br[r[i]],r[i+1])-r[i]);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
