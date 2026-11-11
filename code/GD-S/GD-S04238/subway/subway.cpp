#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int z,t;
};
int c,n,m,d,q,w[500000],k,x,y;
int wz[1000][500];
bool v[500000],a[500][20000];
queue<node> s;
void bfs(){
	node zt={x,w[x]};
	s.push(zt);
	while(!s.empty()){
		zt=s.front();
		s.pop();
		v[zt.z]=1;
		if(zt.z==y){
			cout<<zt.t<<'\n';
			break;
		}
		for(int i=0;i<n;i++){
			if(a[i][zt.z]){
				for(int j=zt.z+1;j<m;j++){
					if(a[i][j]&&v[j]==0){
						s.push({j,zt.t+wz[zt.z][i]});
					}
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int sr;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>sr>>wz[sr][i];
			a[i][sr]=1;
		}
	}
	while(q--){
		cin>>x>>y;
		bfs();
	}
	return 0;
} 
