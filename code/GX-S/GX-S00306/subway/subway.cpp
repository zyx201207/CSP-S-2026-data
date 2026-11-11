#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y;
int a[10005][10005],t[10005][10005],w[100005];//a[i][j] 表示第 i 条线路经过的第 j 个地铁站,t[i][j] 表示从该地铁站的站厅走到第 i 条线的站台需要的时间。
int solve(int x,int y,int c)
{
    int tot=0;
	if(c>=7&&c<=11)
    {
        for(int i=1;i<=n;i++)
        {
            if((a[i][1]==x||a[i][2]==y)||(a[i][1]==y||a[i][2]==x)) return t[i][1]+t[i][2];
            else if(a[i][1]==x) return t[i][1]+solve(a[i][2],y,c);
            else if(a[i][2]==x) return t[i][2]+solve(a[i][1],y,c);
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);

    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)//m stations
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)//n lines
    {
		cin>>k;
        for(int j=1;j<=k;j++)
        {
			cin>>a[i][j]>>t[i][j];
		}
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        cout<<solve(x,y,c)+w[x]+w[y]<<endl;

    }

	return 0;
	/*
	 *Maybe it's the worst fail in my whole life.Now I have abandoned it
	 *becouse of my low knowledge level.I have regreted a lot about it.
	 *I blieve that I will do it again if i have enough time.And I wish
	 *that's true.I love myself forever.
	 *                                                         sinCe
	 *                                                      31 Oct. 2026 
	 */ 
}
