#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
struct st{
	ll a,t;

};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<ll>ve(m);
	for(int i=0;i<m;i++){
		cin>>ve[i];
	}
	vector<vector<ll,st>>v;
	ll z,a,t;
	for(int i=0;i<n;i++){
		cin>>z;
		for(int j=0;j<z;j++){
			cin>>v[i][j].a>>v[i][j].t;
		}
	}
	
	return 0;
}
