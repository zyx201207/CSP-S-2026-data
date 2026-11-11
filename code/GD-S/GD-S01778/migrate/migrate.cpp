#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,a[500006],last[500006],c,T;
void solve(){
	for(int i = 1;i <= n; i++)
		last[i] = 0;
	cin >> n >> d;
	for(int i = 1;i <= n; i++)
		cin >> a[i];
	for(int i = 2;i <= n; i++){
		int l = 1,r = i-1,pos = i;
		while(l <= r){
			int mid = (l+r)>>1;
			if(a[i]-a[mid] <= d){
				pos = mid;
				r = mid-1; 
			}else l = mid+1;
		}
		last[i] = pos; 
	}
	int Ans = 0;
	for(int i = 1;i <= n; i++)
		for(int j = i+1;j <= n; j++){
			vector<int> v;
			int pos = j;
			bool P = 1;
			v.push_back(pos);
			while(pos > i){
				if(last[pos] == pos){
					P = 0;
					break;
				}
				pos = max(last[pos],i);
				v.push_back(pos);
			}
			reverse(v.begin(),v.end());
			int Last = v[0],cnt = 0;
			for(int k = 1;k < v.size()-1; k++){
				int u = v[k];
				int o = u-1;
				if(Last < o&&last[v[k+1]] <= o){
					if(last[o] < Last) P = 0;
					else cnt++;
				}
			}
			if(cnt == 1&&v.size() > 2) Ans++;
		}
	cout << Ans << endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--)
		solve();
	return 0;
}
