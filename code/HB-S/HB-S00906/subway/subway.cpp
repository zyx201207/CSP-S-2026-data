#include <bits/stdc++.h>
using namespace std;
int const mx=5e5+10;
int sub[mx],xan[505][mx],t[505][mx];
int c,n,m,d,q,x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
 	cin>>c>>n>>m>>d>>q;
 	for(int i=1;i<=m;i++) cin>>sub[i];
 	for(int i=1;i<=n;i++)
 	{
	    int k;
	    cin>>k;
	    for(int j=1;j<=k;j++)
	    {
			xan[i][0]=k;
			cin>>xan[i][j]>>t[i][j];
		}
    }
    for(int i=1;i<=q;i++)
    {
		int ans=0;
	    cin>>x>>y;
	    ans=ans+sub[x]+sub[y];
	    ans=ans+xan[1][x]+xan[2][y];
	    cout<<ans<<endl;
    }
    return 0;
}
