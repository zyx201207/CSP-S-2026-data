#include <bits/stdc++.h>
using namespace std;
long long c,t,x[2000006],n,d,ans=0;
bool b[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		for(int i=1;i<=n;i++){
			if(x[i]-x[1]<=d && x[n]-x[i]<=d){
				b[i]=1;
				ans=(i-1)*(n-i);
				break;
			}
		}
		cout << ans;
	}
	return 0;
}
