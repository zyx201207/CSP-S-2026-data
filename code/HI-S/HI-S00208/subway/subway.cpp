#include<bits/stdc++.h>
#define int long long
#define QWQ return 0;}
#define OoO signed main(){
using namespace std;
const int M=5e5+5;
int c,n,m,d,q;
int w[505];
int t[M][505];
int soc(int z1,int z2){
	
}
OoO
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		for(int j=1;j<=x;j++){
			int z; cin>>z;
			cin>>t[z][i];
		}
	}
	for(int i=1;i<=q;i++){
		int begin,end;
		cin>>begin>>end;
		cout<<soc(begin,end);
	}
QWQ
