#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		cin>>n>>d;
		for(int j = 1;j <= n;j++){
			cin>>a[j];
		}
		int ans = 0;
		for(int j = 1;j <= n;j++){
			for(int k = j+1;k <= n;k++){
				if(abs(a[k]-a[j]) <= 2*d&&d-abs(a[k]-a[j])%d == 1&&abs(a[k]-a[j]) != 1&&abs(a[k]-a[j]) !=2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
