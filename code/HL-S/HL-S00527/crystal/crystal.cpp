#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define int long long
const int N = 5e5+10;
int a[N];
int b[N];
int n,m,sum;
int ans,ansTmp;
void solve1(){
	sort(a+1,a+n+1,[](int A,int B){
		return A>B;
	});
	for(int i = 1;i<n;i++){
		int t = m;
		for(int j = i+1;j<=n;j++){
			if(a[i] - a[j] <= t){
				//a[j] = a[i];
				t-= (a[i] - a[j]);
				b[i]++;
				ans = max(b[i],ans);
				
			}else{
				break;
			}
		}
	}
	ans++;
	cout << ans << endl;
}

void solve2(){
	sort(a+1,a+n+1);
	for(int i = 1;i<n;i++){
		b[i] = a[i+1]-a[i];
	}
	for(int i = 1;i<n;i++){
		if(m-b[i] >= 0){
			m-= b[i];
			ans++;
		}else{
			break;
		}
	}
	ans++;
	cout << ans;
}
//T1
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=5e3){
		solve1();
	}else{
		solve2();
	}
	return 0;
}