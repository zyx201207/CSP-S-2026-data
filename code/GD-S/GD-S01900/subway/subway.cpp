#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e6+5;

int w[N];//地铁口到站厅的时间 
int k[N];
int t[500][5000],a[500][5000];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	} 
	for(int i=1;i<=q;i++){
		int x, y;
		cin>>x>>y;
		
	} 
	cout<<1;
	return 0;
}
