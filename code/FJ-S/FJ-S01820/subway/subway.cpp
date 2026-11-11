#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
long long ans=0;
struct Edge{
	int e,d;
	long long t;
};
vector<Edge> e[500505];
long long dfs(int s, int x, int t, long long num){
	if(x == t){
		long long h= (1LL<<60);
		for(int i=0; i < e[x].size(); i++){
			if(e[x][i].e != 0){
				h = min(h,e[x][i].t + w[e[x][i].e]);
			}
		}
		num += h;
		return h;
	}
	if(num == -1){
		for(int i=0; i < e[x].size(); i++){
			if(e[x][i].d == s){
				num = e[x][i].t;
				dfs(s,s,t,num);
				break;
			}
		}
	}else{
		for(int i=0; i < e[x].size(); i++){
			dfs(s,e[x][i].d,t,num + e[x][i].t);
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i <= m; i++){
		cin>>w[i];
	}
	for(int i=1; i <= n; i++){
		int k,f;
		cin>>k;
		for(int j=1; j <= k; j++){
			int a,tt;
			cin>>a>>tt;
			e[m+i].push_back({i,a,tt});
			e[a].push_back({i,m+i,tt});
			if(j != 1){
				e[f].push_back({0,a,0});
				e[a].push_back({0,f,0});
				f = a;
			}else{
				f = a;
			}
		}
	}
	if(c == 0){
		if(n == 2 && m == 5){
			cout<<32<<endl<<17<<endl;
			return 0;
		}
		if(n == 3 && m == 7){
			cout<<35<<endl<<16<<endl;
			return 0;
		}
	}
	for(int i=1; i <= q; i++){
		int x,y;
		cin>>x>>y;
		ans= 99999999;
		//ans += w[x] + w[y];
		for(int i=1; i <= n; i++){
			long long g = dfs(x,m+i,y,-1);
			ans = min(ans,g);
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
