#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int w[N];
int a1[N],a2[N],a3[N];
int t[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c,m,n,d,q;
	cin>>c>>n>>m>>d>>q;//测试点编号 
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		
		for(int j=1;j<=k;j++)
		{
			int a,tt;
			cin>>a>>tt;
			if(i==1)
			{
				a1[a]++;
				t[a][1]+=tt;
			}
			if(i==2)
			{
				a2[a]++;
				t[a][2]+=tt;
			}
			if(i==3)
			{
				a3[a]++;
				t[a][2]+=tt;
			}
		}
	
	}
	while(q--)
	{
		int time1=0x3f3f3f3f,time2=0x3f3f3f3f;
		long long ans=0;
		int x,y;
		cin>>x>>y;
		ans+=w[x]+w[y];
		if(a1[x]&&a1[y])
		{
			time1=min(t[x][1]+t[y][1],time1);
		}
		if(a2[x]&&a2[y])
		{
			time1=min(t[x][2]+t[y][2],time1);
		}
		if(a3[x]&&a3[y])
		{
			time1=min(t[x][3]+t[y][3],time1);
		}
		if(time1!=0x3f3f3f3f)
			ans+=time1;
		else//不直达 
		{
			for(int i=1;i<=m;i++)
			{
				if((a1[i]&&a2[i])&&((a1[x]||a2[x])&&(a1[y]||a2[y])))//a1 a2线共站 
				{
					time1=min(t[i][1]+t[i][2],time1);
					if((a1[x]&&a2[y]))
					{
						time2=min(t[x][1]+t[y][2],time2);
					}
					if(a2[x]&&a1[y])
					{
						time2=min(t[x][2]+t[y][1],time2);
					}
				}
				if((a2[i]&&a3[i])&&((a2[x]||a3[x])&&(a2[y]||a3[y])))//a2 a3线共站 
				{
					time1=min(t[i][2]+t[i][2],time1);
					if((a2[x]&&a3[y]))
					{
						time2=min(t[x][2]+t[y][3],time2);
					}
					if(a3[x]&&a2[y])
					{
						time2=min(t[x][3]+t[y][2],time2);
					}
				}
				if((a1[i]&&a3[i])&&((a1[x]||a3[x])&&(a1[y]||a3[y])))//a1 a3线共站 
				{
					time1=min(t[i][1]+t[i][3],time1);
					if((a1[x]&&a3[y]))
					{
						time2=min(t[x][1]+t[y][3],time2);
					}
					if(a3[x]&&a1[y])
					{
						time2=min(t[x][3]+t[y][1],time2);
					}
				}
			}
			ans+=time1;
			ans+=time2;
			//cout<<time1<<" ";
		}
		
		cout<<ans<<endl;
	} 
	return 0;
}
