#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int maxn=1e5*5+10;
int tstid,n,m,d,q,ots[maxn],a[maxn],t[maxn];
int cg[1000][1000];
struct xx{
	int li,ti;
};
vector<xx>su[maxn];
signed main(){
	
	freopen("subway.in","r",stdin) , freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	
	cin>>tstid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>ots[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i]>>t[i];
			su[a[i]].push_back({i,t[i]});
		}
	}
	
	memset(cg,0x3f,sizeof(cg));
	
	for(int i=1;i<=m;i++)
	{
		int len=su[i].size();
		for(int j=0;j<len;j++)
		{
			for(int k=0;k<len;k++)
			{
				int l1=su[i][j].li ,l2=su[i][k].li ,d1=su[i][j].ti ,d2=su[i][k].ti;
				cg[l1][l2]=cg[l1][l2]=min({cg[l1][l2],cg[l1][l2],d1+d2});
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			cg[i][i]=0;
			for(int j=1;j<=n;j++)
			{
				cg[i][j]=cg[j][i]=min({cg[i][j],cg[j][i],cg[i][k]+cg[k][j],cg[k][i]+cg[j][k]});
			}
		}
	}
	
	while(q--)
	{
		int st,ed;
		cin>>st>>ed;
		int M=1e18;
		int sl=su[st].size(),el=su[ed].size();
		for(int i=0;i<sl;i++)
		{
			for(int j=0;j<el;j++)
			{
				int al=su[st][i].li,bl=su[ed][j].li;
				M=min(M,cg[al][bl]+su[st][i].ti+su[ed][j].ti);
			}
		}
		cout<<M+ots[st]+ots[ed]<<'\n';
	}
	
	
	return 0;
}
