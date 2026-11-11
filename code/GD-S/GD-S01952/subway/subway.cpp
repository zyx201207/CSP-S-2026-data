#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int n,m,d,q,w[maxn],a[505][maxn],t[505][maxn],k;
int b[maxn];
void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)    cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
		    cin>>a[i][j]>>t[i][j];
			b[a[i][j]]+=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,sum;
		cin>>x>>y;
		sum=w[x]+w[y]+b[x]+b[y];
		cout<<sum<<endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1,c;
//	cin>>T;
	cin>>c;
	while(T--)    solve();
}
