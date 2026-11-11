#include <iostream>
#include <cmath>
using namespace std;
int c,t,n,k,minn=1e9;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		minn = 1e9;
		for(int i = 1;i <= n-1;i++){
			int u,v;
			cin >> u >> v;
			minn=min(minn,abs(u-v));
		}
		cout << minn < "\n";
	}
	return 0;
}
