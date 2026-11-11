#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c[1000005],sum,cnt,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> a >> b;
	for(int i = 1; i <= a; i++){
		cin >> c[i];
	}
	sort(c+1,c+1+a);
	for(int i = 1,j = 1; i <= a; i++){
		while((c[i] * cnt) - sum > b){
			sum -= c[j];
			j++;
			cnt--;
		}
		sum += c[i];
		cnt++;
		ans = max(ans,cnt);
	}
	cout << ans;
	return 0;
} 
