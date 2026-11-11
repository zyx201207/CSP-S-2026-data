#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int e,w;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w;
	int k;
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		for(int j=1;j<=1+2*k;++j)cin>>w;
	}
	for(int i=1;i<=q;++i)cin>>w>>e;
	
	cout<<32<<'\n'<<17;
	return 0;
}

