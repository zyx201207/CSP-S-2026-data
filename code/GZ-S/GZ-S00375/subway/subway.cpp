//贵阳市南明区李端棻中学刘沛羽GZ-S00375 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t;
struct Edge{
	int to;
	long long w;
};

vector<Edge> g[500000];
int timea[500000];
vector<long long> line[505],sta[500000];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>timea[i];
	}
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		for(int j=0;j<temp;j++){
			int a;
			cin>>a>>t;
			line[i].push_back(a);
			sta[a].push_back(i);
		}
	}
	while(q--){
		int start,end;
		cin>>start>>end;
		for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				if(sta[start][i]==sta[end][j]){
					cout<<timea[start]+timea[end]<<'\n';
					return 0;
				}
				
			}
		}
		
	}
	return 0;
}

