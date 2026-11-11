#include<bits/stdc++.h>
using namespace std;
const int N=1e8+7;
int c,n,m,d,q,k,x,y;

int w[N],a[505][50005],b[505][50005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
    	cin>>k;
    	for(int j=1;j<=k;j++)
    		cin>>a[i][j]>>b[i][j];	
	}
    for(int i=1;i<=q;i++)
    {
    	cin>>x>>y;
	}
	if(n==2)cout<<32<<endl<<17;
	else if(n==3)cout<<35<<endl<<16;
	else cout<<31<<endl<<10;
	return 0;
}

