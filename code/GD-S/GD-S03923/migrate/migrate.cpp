#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
int c,t,n,d,x[N],e[N][N],ans,dd[N][N];
void solve(){
	ans=0;
	int cha;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i],cha=x[i]-x[i-1];
	int pp=d/cha;
	if(pp==1||pp>=n/2){
		cout<<0;
		return;
	}
	cout<<pp*(pp+1)/4;
//	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
