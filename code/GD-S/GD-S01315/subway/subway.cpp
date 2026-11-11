#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
class G{
	private:
		vector<vector<pair<int,int>>> side;
		int n;
	public:
		void add(int u,int v,int w){
			side[u].push_back(make_pair(v,w));
			//cout<<side[3][0]<<endl;
			side[v].push_back(make_pair(u,w));
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
					if(y+side[x][i].second<d[side[x][i].first]){
						d[side[x][i].first]=y+side[x][i].second;
						C.push_back(make_pair(side[x][i].first,y+side[x][i].second));
					}
				}
			}
			return d[v];
		}
	G(int m){
		side.assign(m+1,vector<pair<int,int>>(1,make_pair(0,0)));
		n=m;
	}
};
vector<int> wei(1,0);
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,m,n,d,q,w,a,t,ai;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w;
		wei.push_back(w);
	}
	G grap(m);
	vector<pair<int,int>> sid;
	if(c>=7&&c<=11){
		
	for(int k=1;k<=n;k++){
		sid.clear();
		cin>>ai;
		for(int l=1;l<=ai;l++){
			cin>>a>>t;
			sid.push_back(make_pair(a,t));
		}
		grap.add(sid[0].first,sid[1].first,sid[0].second+sid[1].second);
	}
	
	}else{
		
	for(int k=1;k<=n;k++){
		sid.clear();
		cin>>ai;
		for(int l=1;l<=ai;l++){
			cin>>a>>t;
			sid.push_back(make_pair(a,t));
		}
		for(int i=0;i<ai;i++){
			for(int j=i+1;j<ai;j++){
				grap.add(sid[i].first,sid[j].first,(sid[i].second+sid[j].second));
			}
		}
	}
	
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		int res=grap.Di(x,y)+wei[x]+wei[y];
		cout<<res<<endl;
	}
	return 0;
} 
