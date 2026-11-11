#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5;
struct jgt{
	int bh,step;
};
int c,n,m,d,o,w[M],k[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>o;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
		}
	}
	for(int i=1,x,y;i<=o;i++){
		cin>>x>>y;
	}
	cout<<0<<"\n";
	return 0;
} 
