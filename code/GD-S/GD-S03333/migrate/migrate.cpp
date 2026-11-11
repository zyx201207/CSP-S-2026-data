#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,x[100010],a[100010];
	cin >> c >> t;
	for(int i = 1;i<=t;i++){
		int n,d,ans=0;
		cin >> n >> d;
		for(int j = 1;j<=n;j++){
			cin >> x[j];
			if((x[n]-x[1])%d==0){
				ans = 0;
			}
		}
		
		for(int j =1;j<n;j++){
			a[j] = x[j+1]-x[j];
		}
		
		cout << ans;
	}
	return 0;
}
