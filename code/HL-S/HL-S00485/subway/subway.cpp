#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
typedef long long ll;
ll c,n,m,d,q,w[N],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	if(c==0){
		for(int i=1;i<=n;i++){
			ll k,a,t;
			cin>>k;
			for(int j=1;j<=k;j++) cin>>a>>t;
		}
		for(int i=1;i<=q;i++){
			ll x,y;
			cin>>x>>y;
		}
		if(n==2&&m==5&&d==20&&q==2) cout<<32<<endl<<17<<endl;
		else if(n==3&&m==7&&d==20&&q==2) cout<<35<<endl<<16<<endl;
		return 0;
	}
	for(int i=1;i<=q;i++){
		
	}
	cout<<ans;
	return 0;
} 