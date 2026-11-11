#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,d,mp[200005],cnt[200005],len[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for(int i = 1 ; i <= t ; i++){
		memset(cnt,0,sizeof(cnt));
		cin >> n >> d;
		for(int j = 1 ; j <= n ; j++){
			cin >> mp[j];
		}
		memset(len,0x3f3f3f3f,sizeof(len));
		len[1] = 0;
		for(int j = 1 ; j <= n ; j++){
			for(int k = j + 1 ; k <= n && mp[k] - mp[j] <= d ; k++){
				if(len[j] + mp[k] - mp[j] < len[k]){
					len[k] = len[j] + mp[k] - mp[j];
					cnt[k] = 1;
				}else if(len[j] + mp[k] - mp[j] == len[k]){
					cnt[k] += cnt[j];
				}
			}
		}
	}
	return 0;
}
