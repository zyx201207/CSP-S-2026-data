#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> w;
const int N=510;
int k[N],a[N][N],t[N][N];
signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	for(int i=1;i<=m;i++){
		int te;cin>>te;w.push_back(te);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>t[i][j];	
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int sum=w[x-1]+w[y];
		
	}
	return 0;
}