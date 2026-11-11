#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		scanf("%ld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long ans = 0;
	for(int i = n;i >= 1;i--){
		long long cnt = 1,ans1 = 0;
		for(int j = i-1;j >= 1;j--){
			ans1 += a[i]-a[j];
			cnt++;
		}
		if(ans1 <= m){
			//cout << "in" << i << "\n";
			ans = max(ans,cnt);
		}
	}
	printf("%ld\n",ans);
	return 0;
}
