#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
long long a[N],sum[N],ans;
int n,m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 2;i <= n;i++){
		sum[i-1] += a[i]-a[i-1];
	}
	long long cnt1 = m,cnt2 = 0,h = 0;
	for(int i = 1;i <= n;i++){
		cnt1 -= (a[i]-a[i-1])*cnt2;
		cnt2++;
		while(cnt1 < 0){
			cnt1 += sum[i-1]-sum[h];
			h++;
			cnt2--;
		}
		ans = max(ans,cnt2);
	}
	cout << ans << endl;
	return 0;
}
