#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans[5008][508],w[500008],k[508],x[100008],y[100008];
vector<int>a[508],t[508],xl[500008];
struct tt{
	int x,xlid,l;
	bool friend operator < (tt i,tt j){
		i.l >j.l ;
	}
};
struct pp{
	int y,t,xid;
};
vector<pp>px[500008];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int sta,ti;
			cin>>sta>>ti;
			for(int k=0;k<a[i].size();k++){
				px[sta].push_back({a[i][k],t[i][k]+ti,i});
				px[a[i][k]].push_back({sta,t[i][k]+ti,i});
			}
			a[i].push_back(sta);
			t[i].push_back(ti);
			xl[sta].push_back(i);
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) ans[i][j]=1e9;
	//	for(int j=0;j<px[i].size();j++) cout<<px[i][j].y<<" ";
	//	cout<<"\n";
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		priority_queue<tt>p;
		for(int i=0;i<xl[st].size();i++){
			ans[st][xl[st][i]]=0;
			p.push({st,xl[st][i],});
		} 
		int anss=w[st]+w[ed];
		while(!p.empty()){
			tt id=p.top();
			p.pop();
			//cout<<id.x <<" "<<id.xlid <<" "<<id.l <<"\n";
			if(id.x ==ed){
				anss+=id.l ;
				break;
			}
			for(int i=0;i<px[id.x ].size();i++){
			//	cout<<px[id.x ][i].y<<"\n";
				if(id.l +(px[id.x ][i].t)<ans[px[id.x ][i].y][id.xlid  ]){
					ans[px[id.x ][i].y][id.xlid  ]=id.l +(px[id.x ][i].t);
					p.push({px[id.x ][i].y,px[id.x ][i].xid,id.l +(px[id.x ][i].t)});
				}	

			}
		}
		cout<<anss<<"\n";
	} 
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
