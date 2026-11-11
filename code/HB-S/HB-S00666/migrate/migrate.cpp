#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+91;
int c,t,n,d,xi[N],dp[5013][5078][9+1];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0||(11<=c&&c<=12)){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>xi[i];
			}
			int gongcha=xi[2]-xi[1];
			int gg=d/gongcha;
			if(gg<2){
				cout<<0<<endl;
				continue;
			}
			int m=gg*2-1;
			cout<<max(n-m,0ll)<<endl;
		}
	}
	return 0;
}
