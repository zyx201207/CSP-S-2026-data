#include<bits/stdc++.h>
#define fs first
#define sc second
#define N 200005
#define int long long
using namespace std;

int n, len, ans;
int cnt[N], cnt2[N];
char c[N];

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> cnt[i] >> c[i];
		len += cnt[i];
		cnt2[i] = cnt[i];
	}
	
	int pos = 0, ti = n;
	for(int i = 1;pos < len / 2;i++){
//		cout << pos << " " << len << "\n";
		int end = min(pos + cnt2[i], len / 2);
		while(pos < end){
//			cout << c[ti] << " " << cnt[ti] << "\n";
			if(pos + cnt[ti] <= end){
//				cout << c[ti] << " end\n";
				if(c[ti] != c[i]) ans += cnt[ti];
				pos += cnt[ti];
				ti--;
			}
			else{
				int dis = end - pos;
				cnt[ti] -= dis;
				if(c[ti] != c[i]) ans += dis;
				pos = end;
			}
		}
	}
	
	cout << ans;
	
	return 0;
	
} 
