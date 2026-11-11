#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,len = 1,tmp,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	for(int i = 2;i <= n;i++){
		tmp += (a[i] - a[i - 1]) * len;
		if(tmp > m){
			for(int j = i - len;j < i;j++){
				tmp -= a[i] - a[j];
				len--;
				if(tmp <= m){
					break;
				}
			}
		}
		len++;
		ans = max(ans,len);
	}
	cout << ans;
	return 0;
}

