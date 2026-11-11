#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q1,dk[500010],x,y,zt[500010][30],f[500010],xb,ans[3000][3000];
struct sut
{
	long long v,sum;
};
vector<sut>vt[500010];
struct st
{
	long long x,y;
}que[100010];
void floyd()
{
	for (long long k=1;k<=m;k++)
	{
		for (long long i=1;i<=xb;i++)
		{
			long long len=vt[i].size();
			for (long long j=0;j<=len-1;j++)
			{
				f[vt[i][j].v]=min(f[vt[i][j].v],f[i]+vt[i][j].sum);
			}
		}
	}
	return ;
}
bool cmp(st h,st l)
{
	return h.x<l.x;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	long long a=0,b=0;
	xb=1;
	for (long long i=1;i<=m;i++)
	{
		cin>>a;
		vt[xb].push_back({xb+1,a});
		vt[xb+1].push_back({xb,a});
		dk[i]=xb;
		xb+=2;		
	}
	long long q=0;
	for (long long i=1;i<=n;i++)
	{
		cin>>c;
		for (long long j=1;j<=c;j++)
		{
			cin>>a>>b;
			if (j>1)
			{
				vt[zt[q][i]].push_back({xb,0});
				vt[xb].push_back({zt[q][i],0});
			}
			q=a;
			vt[2*a].push_back({xb,b});
			vt[xb].push_back({2*a,b});
			zt[a][i]=xb;
			xb++;
		}
	}
	memset(f,0x3f,sizeof(f));
	f[dk[1]]=0;
	floyd();
	for (long long i=1;i<=q1;i++)
	{
		cin>>que[i].x>>que[i].y;
	}
	sort(que+1,que+1+q1,cmp);
	long long su=que[1].x;
	memset(f,0x3f,sizeof(f));
	f[dk[que[1].x]]=0;
	floyd();
	for (long long i=1;i<=q1;i++)
	{
		if (su!=que[i].x)
		{
			if (ans[que[i].y][que[i].x]>0)
			{
				cout<<ans[que[i].y][que[i].x]<<endl;
			}
			memset(f,0x3f,sizeof(f));
			f[dk[que[i].x]]=0;
			floyd();
			cout<<f[dk[que[i].y]]<<endl;
			ans[que[i].y][que[i].x]=f[dk[que[i].y]];
			ans[que[i].x][que[i].y]=f[dk[que[i].y]];
		}else
		{
			cout<<f[dk[que[i].y]]<<endl;
			su=que[i].x;
		}
	}
	return 0;
}
