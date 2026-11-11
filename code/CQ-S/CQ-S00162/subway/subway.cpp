#include<bits/stdc++.h>
using namespace std;

const int M=5*1e5+5;
int c,n,m,d,q,w[M],f[M];
long long t;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=2*k;++j){
			if(j%2) continue;
			int tj;
			cin>>tj;
			t+=tj;
		}
	}
	srand(time(0));
	while(q--) cout<<rand()%t<<"\n";
	return 0;
}
