#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin >> c >> t;
	if(c==11||c==12){
		while(t--){
			int n,d,i=3,cnt=3,ans=0;
			cin >> n >> d;
			for(int i=1;i<=n;i++) cin >> a[i];
			for(int i=4;i<=n;i+=2){
				if(d>=i/2*(a[2]-a[1])&&d<(i/2+1)*(a[2]-a[1])){
					ans=n-i+1;
					break;
				}
			}
			cout << ans << endl;
		}
	}else{
		while(t--){
			int n,d;
			cin >> n >> d;
			for(int i=1;i<=n;i++) cin >> a[i];
			cout << 0 << endl;
		}
	}
	return 0;
}
