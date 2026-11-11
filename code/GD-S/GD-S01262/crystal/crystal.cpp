#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,a[N];
	cin >> n >> m;
	bool cmpA = true,cmpB = true;
	int cha = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i > 2)
			if(a[i] - a[i - 1] != a[i - 1] - a[i - 2])
				cmpB = false;
		if(a[i] != i)cmpA = false;
	}	
	sort(a + 1,a + n + 1);
	if(!cmpA && !cmpB){
		ll d[N];
		ll maxn = 1;
		for(int i = n;i >= 1;i--){
			ll mm = m;
			ll sum = 1;
			for(int i = 1;i <= n;i++){
				d[i] = a[i];
			}
			while(mm){
				if(d[i - sum] == d[i]){
					sum++;
					continue;
				}
				if(sum == i){
					break;
				}
				mm--;
				d[i - sum]++;
				if(d[i - sum] == d[i]){
					sum++;
				}
			}
			maxn = max(maxn,sum);
		}
		cout << maxn;
	}
	else if(cmpA){
		ll num = 1;
		for(int i = 1;i <= n;i++){
			m = m - i;
			if(m >= 0){
				num++;
			}
		}
		cout << num;
	}
	else if(cmpB){
		ll vum = 1;
		ll cha = a[2] - a[1];
		for(int i = 1;i <= n;i++){
			m -= (i * cha);
			if(m >= 0){
				vum++;
			}
			else{
				break;
			}
		}
		cout << vum;
	}
}
