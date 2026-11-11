#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int M=5e5+10,N=510;
ll w[M],k[N],a[N],t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans;
		ans+=w[x]+t[x]+w[y]+t[y];//n<=2这一块 
		cout<<ans<<endl;
	}
	return 0;
}
//赛百味 
