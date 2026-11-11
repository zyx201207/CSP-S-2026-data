#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q,w[500005],k,A,T,x,y,q[1000005];
vector<int> t[505];
vector<int> a[505];
vector<int> to[500005];
vector<int> s[500005];
bool b[500005];
int main()
{
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	const int N=m+1;
	int f[N];
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>A>>T;
			a[i].push_back(A);
			t[i].push_back(T);
			to[A].push_back(i);
			s[A].push_back(j);
		}
	}
	for(int i=1;i<=Q;i++)
	{
	    memset(f,127/3,sizeof(f));
		cin>>x>>y;
		f[x]=0;
		int head=0,tail=0;
		q[++tail]=x;
		b[x]=1;
		while(head<tail)
		{
			int xx=q[++head];
			//cout<<xx<<" "<<f[xx]<<endl;
			b[xx]=0;
			for(int i=0;i<to[xx].size();i++)
			{
				int k=to[xx][i];
				for(int j=0;j<a[k].size();j++)
				{
					int yy=a[k][j];
					int kk=s[xx][i];
					int yyy=t[k][kk-1]+t[k][j];
					if(yy==xx) continue;
					//cout<<f[xx]+yyy<<"!";
					if(f[yy]>=f[xx]+yyy&&f[xx]+yyy<=f[y])
					{
						f[yy]=f[xx]+yyy;
						if(b[yy]==0)
						{
							q[++tail]=yy;
							b[yy]=1;
						}
					}
				}
			}
		}
		cout<<f[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
