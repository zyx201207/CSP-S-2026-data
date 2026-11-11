#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[500010];
int t[300010];
bool used[300010];
int sl[500010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int x = 1;x <= n;x ++){
		int cnt = 0;
		for(int i = 1;i <= m;i ++)used[i] = false;
		for(int i = 1;i <= n;i ++)sl[i] = 0;
		for(int i = x;i <= n;i ++){
			++cnt;
			if(!used[a[i]]){
				used[a[i]] = true;
				sl[cnt] = a[i];
			}else{
				for(int j = cnt;j >= 1;j --){
					if(sl[j] == a[i]) break;
					used[sl[j]] = false;
					sl[j] = 0;
					cnt--;
				}
			}
		}
		for(int i = 1;i <= cnt;i ++){
			cout << sl[i] << ' ';
			t[sl[i]]++;
		}
		cout << '\n';
	}
	for(int i = 1;i <= m;i ++){
		cout << t[i] << ' ';
	}
	return 0;
}
