#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d,x[305],ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i==j||x[j]-x[i]<=d||i-j==1||i-j==-1) continue;
				int l = x[j]-x[i];
				if(l==2*d-1){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
