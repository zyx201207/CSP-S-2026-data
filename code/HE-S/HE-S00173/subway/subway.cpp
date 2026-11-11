#include<bits/stdc++.h>
using namespace std;

const int inf=1e8+5;

int c,m,n,d,q;
int w;//你怎么知道我上午刚复习了dij 
int a,t;//但是现在我忘了 
int k;//本来可以用dij打性质B的部分分的。。 
//额不对好像不是最短路，但我还是不会。 

int main( )
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	int ans=inf;
	for(int i=1;i<=m;i++)
	{
		cin>>w;
		ans=min(w,ans);
	}	
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a>>t;
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y; 
		cout<<ans;
	}
	
	return 0;
}
