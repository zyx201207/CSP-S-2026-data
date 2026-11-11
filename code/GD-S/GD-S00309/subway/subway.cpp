#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
int a[505][500005];
int t[505][500005];

void solve(){
	int x,y;cin>>x>>y;
	
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
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
	while(q--){
		solve();
	}
	return 0;
} 
/*


+   +   +   +
1 4 2 5 5 h
s   1
2 6 3 1 7 2

3 2 5 h 4 6 6 7
            e


*/
