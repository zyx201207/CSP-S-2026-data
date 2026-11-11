#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,n,m,d,q,sum;

int main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q; 
	
	//m个地铁站 
	for(int i=1;i<=m;i++){
		ll w;
		cin>>w;//站厅到地铁口的时间 
		if(i==1 || i==m)sum+=w;
	}
	
	//n条线路 
	ll t;
	for(int i=1;i<=m;i++){
		ll k,a;
		cin>>k;//该线路经过的地铁站数量 
		for(int j=1;j<=k;j++){
			//经过的地铁站编号 
			cin>>a;
			cin>>t;//站厅到该线路的时间 
		}
	}
	
	cout<<t*(n-1)+sum;
	
	return 0;
}
