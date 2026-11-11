
#include<iostream>
using namespace std;
const int N=5e5+5;
int n,c,d,q,m,x,y,tmin=0;
int w[N],a,t[505][N]={-1},k;
int d(int z,int v){
	int ans=0;
	for(int i=1;i<=m;i++){
		if(t[i][z]!=-1||)
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a;
			cin >> t[a][j];
		}
	}
	while(q--){
		cin >> x >> y;
		
		tmin+=w[x]+w[y];
		cout << tmin;
	}
	return 0;
}

