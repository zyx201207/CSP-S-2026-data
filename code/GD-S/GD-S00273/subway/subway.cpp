#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005],ne[500005];
struct edge{
	long long a,t;
};
struct trip{
	int be,en;
}r[500005];
vector<edge> k;
queue<int> s;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	while(c--){
		for(int i=1;i<=m;i++){
			cin>>m;
		}
		
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>ne[i];
			for(int j=1;j<=ne[i];j++){
				cin>>x>>y;
				
				
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r[i].be>>r[i].en;
		}
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
