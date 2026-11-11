#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
typedef unsigned long long ull;

int c,n,m,d,q;
int a[505][50005];
int t[505][50005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);
	for(int i=1;i<=m;i++) cin>>w[m];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		if(k==1) continue;
		
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans+=w[x]+w[y]+t[x][y];
		cout<<ans<<'\n';
	}
}
