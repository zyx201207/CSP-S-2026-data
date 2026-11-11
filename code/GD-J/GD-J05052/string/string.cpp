#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
struct str{
	int cnt; char d;
};
int n;
ll a[N];
char c[N];
ll ans = 0LL;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	if(n == 1){
		cout << "0\n";
		return 0;
	}
	int l = 1,r = n;
	ll sl = a[1],sr = a[n];
	char cl = c[1],cr = c[n];
	while(l < r){
		if(cl == cr && sl == sr){
			l++,r--;
			sl = a[l],sr = a[r];
			cl = c[l],cr = c[r];
			continue;
		}else if(cl != cr && sl == sr){
			ans += sl;
			l++,r--;
			sl = a[l],sr = a[r];
			cl = c[l],cr = c[r];
			continue;
		}else if(cl == cr && sl != sr){
			if(sl > sr){
				sl -= sr;
				r--;
				sr = a[r];
				cr = c[r];
			}else{
				sr -= sl;
				l++;
				sl = a[l];
				cl = c[l];
			}
		}else{
			if(sl > sr){
				ans += sr;
				sl -= sr;
				r--;
				sr = a[r];
				cr = c[r];
			}else{
				ans += sl;
				sr -= sl;
				l++;
				sl = a[l];
				cl = c[l];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
