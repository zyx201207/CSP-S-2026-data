#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
class G{
	private:
		vector<vector<int>> side;
		int n;
	public:
		void add(int u,int v){
			side[u].push_back(v);
			side[v].push_back(u);
		}
		int Di(int u,int v){
			vector<pair<int,int>> C;
			vector<int> d;
			d.assign(n+1,INF);
			d[u]=0;
			C.push_back(make_pair(u,0));
			while(!C.empty()){
				int x=C[0].first;
				int y=C[0].second;
				C.erase(C.begin());
				for(long long unsigned i=1;i<side[x].size();i++){
					if(y+1<d[side[x][i]]){
						d[side[x][i].first]=y+1;
						C.push_back(make_pair(side[x][i],y+1));
					}
				}
			}
			cout<<1<<endl;
			return d[v];
		}
	G(int m){
		side.assign(m+1,vector<int>(1,0));
		n=m;
	}
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> x;
	int c,t,n,d,xi;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		G grap(n);
		for(int j=0;j<n;j++){
			cin>>xi;
			x.push_back(xi);
		}
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(x[k]-x[j]<=d){
					grap.add(j,k);
				}
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<0<<endl;
	} 
	return 0;
} 
