#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,LOG=35;
int n,m,ans,h;
bool a[N][LOG];
bool vis[N];
signed main(){
	freopen("and.in" ,"r",stdin );
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	h=n;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%lld",&x);
		for(int j=LOG-1;x;j--){
			a[i][j]=x%2;
			x/=2;
		}
	}
	for(int i=1;i<LOG;i++){
		ans=(ans<<1);
		int _h=h;
		queue<int> vis2; 
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(!a[j][i]){
				vis2.push(j);
				_h--;
				continue;
			}
		}
		if(_h>=m){
			ans++;
			h=_h;
			while(!vis2.empty()){
				vis[vis2.front()]=1;
				vis2.pop();
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

