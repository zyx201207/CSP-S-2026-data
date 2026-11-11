#include<bits/stdc++.h>
using namespace std;
long long c,t,n;
long long a[2000002],d;
long long tmp[2000002],cnt[2000002];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		long long ans = 0;
		for(int i = 0;i < n;i++){//cong/ i kai- shi|
			for(int j = i;j < n;j++)tmp[j] = 0x3f3f3f3f3f3f3f3f,cnt[j] = 0;
			tmp[i] = 0,cnt[i] = 1;
			for(int j = i;j < n;j++){
				if(cnt[j] == 2){
					ans++;/*cout << i << " " << j << "  ";*/
				}
				for(long long k = j + 1;k < n && a[k] - a[j] <= d;k++){
					if(tmp[j] + 1 < tmp[k])tmp[k] = tmp[j] + 1,cnt[k] = 1;
					else if(tmp[j] + 1 == tmp[k])cnt[k]++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
