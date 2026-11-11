#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
int n,m,x,ans,res;
vector<int> v[35];
bool z[N],zz[N],lcx;
int Pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	if(y&1)
	{
		return Pow(x*x,y/2)*x;
	}
	return Pow(x*x,y/2);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=30;j>=0;j--)
		{
			if(x>=Pow(2,j))
			{
				x-=Pow(2,j);
				v[j].push_back(i);
			}
		}
	}
	for(int i=30;i>=0;i--)
	{
		if(v[i].size()>=m)
		{
			if(lcx)
			{
				memset(zz,0,sizeof(zz));
				res=0;
				for(auto j:v[i])
				{
					if(!z[j]) res++,zz[j]=1;
				}
				if(res>=m)
				{
					for(int j=1;j<=n;j++) if(!zz[j])
					{
						z[j]=1;
					}
					ans+=Pow(2,i);
				}
			}
			else
			{
				lcx=1;
				for(auto j:v[i])
				{
					zz[j]=1;
				}
				for(int j=1;j<=n;j++) if(!zz[j])
				{
					z[j]=1;
				}
				ans+=Pow(2,i);
			}
		}
	}
	cout<<ans;
	return 0;
}
