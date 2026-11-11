#include <bits/stdc++.h> 
using namespace std;
int c,n,m,d,q;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	//n地铁线路数
	//m地铁站数
	//d每个地铁站最多被几条线路经过
	//q出行计划数
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i]
		for(int i=1;j<=k[i]*2;j++){
			cin>>a[i][j/2]>>t[i][j/2];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
}
