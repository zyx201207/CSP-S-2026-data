#include<bits/stdc++.h>
using namespace std;
int w[100005],a[1005][1005],check[10005],b[1005][1005];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c, n, m, d, q;
    cin>>c>>n>>m>>d>>q;
    int aw,tw;
    for(int i=1;i<=m;i++)
    {
    	cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>aw>>tw;
			if(check[aw]!=0)
			{
				b[check[aw]][i]=aw;
			}
			check[aw]=i;
			a[i][aw]=tw;
		}
	}
	int x,y,sum=0;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(a[i][x]!=0&&a[i][y]!=0)
		{
			sum+=w[x]+a[i][x]+a[i][y]+w[y];
			cout<<sum<<endl;
			sum=0;
			continue;
		}
	}
	return 0;
}

