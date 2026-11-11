//string
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 7;
int n,a[N];
char c[N];
int sum,cnt,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> c[i],sum += a[i];
	int mid = (sum + 1) / 2,idx = 0;
	for(int i = 1;i <= n;i++){
		cnt += a[i];
		if(cnt >= mid){ idx = i; break; }
	}
	int j = n,left = a[n];
//	cout << idx << endl << endl;
	for(int i = 1;i <= idx;i++){
		int num = a[i];
		while(j >= idx){
//			cout << a[j] << ' ';
			if(c[i] != c[j]){
				if(a[i] <= a[j]){ ans += a[i]; a[j] -= a[i]; break; }
				else if(a[i] > a[j]) ans += a[j],a[i] -= a[j],j--;
			}
			else{
				if(a[i] <= a[j]){
					a[j] -= a[i];
					break;
				}
				else if(a[i] > a[j]) a[i] -= a[j],j--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
