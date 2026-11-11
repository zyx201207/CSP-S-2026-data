#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x7f7f7f7f7f7f7f7f

const int N=2e6+5;
int C,T,n,d;
int x[N],c[N];
int F[505][505];
int ans;

int zxc;
inline void dfs(int l,int r,int c[])
{
	int pos=l,qwe=0,asd=0;
	for(int i=l;i<=r;++i)
	{
		if(c[i]&&x[i]-x[pos]<=d)
		{
			asd++;
			pos=i;
			qwe++;
		}
		else if(c[i]&&x[i]-x[pos]>d) return ;
	}
	if(qwe&&asd==F[l][r]) zxc++;
	for(int i=l;i<=r;++i)
	{
		c[i]=1;
		dfs(l,r,c);
		c[i]=0;
		dfs(l,r,c);
	}
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>C>>T;
	while(T--)
	{
		ans=0;
		cin >>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		int cha=x[2]-x[1];
		bool f=0;
		for(int i=2;i<=n;++i) if(cha!=x[i]-x[i-1]) {f=1;break;}
		if(!f)
		{
			int pos=0;
			for(int i=1;i<=n;++i)
			{
				if(x[i]-x[1]>d*2-cha)
				{
					pos=i-1;
					break;
				}
			}
//			cout <<pos<<' '; 	
 			if(x[n]-x[1]==d*2-cha) cout <<1<<'\n';
			else if(pos<=2) cout <<0<<'\n';
			else cout <<n-pos+1<<'\n'; 
		}
		else
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=i+1;j<=n;++j)
				{
					int l=i+1,r=j,sum=0,num=1;
					while(l<=r)
					{
						if(sum+x[l]-x[l-1]<=d)
						{
							sum+=x[l]-x[l-1]; 
						}
						else
						{
							sum=x[l]-x[l-1];
							num++;
						}
						l++;
					}
					F[i][r]=num;
				}
			}
//			cout <<F[1][4]<<'\n';
			for(int i=1;i<=n;++i)
			{
				for(int j=i+1;j<=n;++j)
				{
					dfs(i,j,c);
					if(zxc==2) ans++;
					zxc=0;
					for(int k=i;k<=j;++k) c[k]=0;
				}
			}
		}
	}
}



