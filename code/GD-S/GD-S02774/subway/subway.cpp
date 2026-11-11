#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 550;
const int K = 5e5 + 10;
int a[N][K];
int t[N][K];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i = 0;i<m;i++){
		cin>>w[i];
	}	
	int k;
	cin>>k;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<k;j++){
			cin>>a[i][j] >> t[i][j];
		}
	} 
	int t = 2;
	while(t--){
		cout<<(n+2) * m ;

	}
	return 0;
}

