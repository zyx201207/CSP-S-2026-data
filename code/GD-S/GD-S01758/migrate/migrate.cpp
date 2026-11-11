#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int n;
ll d,x[N],ans;
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		int las=i,fl=0;//fl->额外有fl条路径 
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[j-1]>d) break;
			if(x[j]-x[las]>d){
				if(las>i&&x[j-1]-x[las-1]<=d) fl++;
				if(las>i+1&&x[j-1]-x[las-2]<=d) fl++;
				las=j-1;
			}
			if(fl>=2) break;
			int p=(las>i&&x[j]-x[las-1]<=d)+(las>i+1&&x[j]-x[las-2]<=d);
			if(p+fl==1) ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
}
