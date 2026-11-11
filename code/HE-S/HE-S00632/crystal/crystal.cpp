#include<bits/stdc++.h>
using namespace std;
long long const N = 5e5 + 100;
long long n,m,ans;
long long a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i]; 
	}
	sort(a,a + n);
	s[0] = 0;
	for(int i = 0;i < n;i++){
		int num = a[i] - a[i - 1];
		s[i] = s[i - 1] + num;
	}
	for(int i = 0;i < n;i++){
		long long sum = 0,cnt = 0;
		for(int j = i;j >= 0;j--){
			if(sum + s[i] - s[j] > m){
				break;
			}
			sum = sum + s[i] - s[j];
			cnt++;
		}
		ans = max(ans,cnt);
	}
	cout << ans;
	return 0;
} 
