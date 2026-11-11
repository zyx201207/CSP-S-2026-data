#include<bits/stdc++.h>
using namespace std;
#define int long long
struct ns{
	int su;
	int whe;
};
int c,n,m,d,q;
int w[500005];//口->厅 
vector<int> k[505];//站数与具体站
vector<int> t[505];//厅->地铁台 
vector<ns> s[500005];//哪些地铁 
int a[505][505];//最短路 
int rans[100005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		k[i].push_back(x);
		t[i].push_back(0); 
		for(int j=1;j<=k[i][0];j++){
			cin>>x>>y;
			k[i].push_back(x);
			t[i].push_back(y);
			s[x].push_back({i,j}); 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				a[i][j]=100000000000000;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(ns j:s[i]){
			for(ns p:s[i]){
				a[j.su][p.su]=min(a[j.su][p.su],t[j.su][j.whe]+t[p.su][p.whe]);
			} 
		}
	}
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][p]+a[p][j]);
			}
		}
	}
	int cop=q;
	while(q--){
		cin>>x>>y;
		int ans=100000000000000;
		for(ns i:s[x]){
			for(ns j:s[y]){
				ans=min(ans,a[i.su][j.su]+t[i.su][i.whe]+t[j.su][j.whe]);
			}
		}
		rans[q]=ans+w[x]+w[y];
	}
	for(int i=cop-1;i>=0;i--){
		cout<<rans[i]<<endl;
	}
	return 0;
}

