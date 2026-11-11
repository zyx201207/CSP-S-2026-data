#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n;
ll a[N] , sum;
char c[N];
struct node{
	ll x;
	char c;
}b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	int tot1 = 0;
	ll tmp = 0;
	for(int i = 1;i <= n;i++){
		if(tmp + a[i] >= sum / 2){
			b[++tot1] = {sum / 2 - tmp , c[i]};
			ll bp = a[i];
			a[i] -= (sum / 2 - tmp);
			if(sum % 2 == 0)break;
			if(tmp + bp == sum / 2)a[i + 1]--;
			else a[i]--;
			break;
		}
		tmp += a[i];
		b[++tot1] = {a[i] , c[i]};
		a[i] = 0;
	}
	int lst = n;
	ll cur = a[n] , ans = 0;
	for(int i = 1;i <= tot1;i++){
		ll now = 0 , tmp1 = 0;
		while(1){
			if(now + cur >= b[i].x){
				if(c[lst] != b[i].c)tmp1 += b[i].x - now;
				cur -= (b[i].x - now);
				if(!cur){
					lst--;
					cur = a[lst];
				}
				break;
			}
			if(c[lst] != b[i].c)tmp1 += cur;
			now += cur;
			lst--;
			cur = a[lst];
		}
		ans += tmp1;
	}
	cout << ans;
	return 0;
}
