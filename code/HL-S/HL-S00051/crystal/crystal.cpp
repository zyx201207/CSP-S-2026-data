#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 100;
int n,m,a[N],temp = 0,ans = 0,now = 0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int m2 = m;
	if(n == 1 || m == 0){
		cout << 1 << endl;
		return 0;
	}
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		if(a[i] == a[i - 1]){
			ans++;
			//cout << now << " " << endl;
			continue;
		}
		now = (i - 1) * (a[i] - a[i-1]);
		//cout << a[i] << "    " << now << " " << m << " " << ans << endl;
		if(m - now >= 0){
			ans++;
			m -= now;
		}else{
			//cout << ans << endl;
			break;
		}
	}
	int ansn = ans;
	ans = 0;
	for(int i = 1;i <= n / 2;i++){
		int t = a[i];
		a[i] = a[n - i + 1];
		a[n - i + 1] = t;
	}
	//for(int i = 1;i <= n;i++) cout << a[i] << " ";
	for(int i = 1;i <= n;i++){
		if(a[i] == a[i - 1]){
			ans++;
			//cout << now << " " << endl;
			continue;
		}
		now = (i - 1) * abs(a[i] - a[i-1]);
		//cout << a[i] << "    " << now << " " << m << " " << ans << endl;
		if(m2 - now >= 0){
			ans++;
			m2 -= now;
		}else{
			cout << max(ans,ansn) << endl;
			return 0;
		}
	}
	cout << n << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 100;
int n,m,a[N],temp = 0,ans = 0,now = 0,sum[N];
signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(n == 1 || m == 0){
		cout << 1 << endl;
		return 0;
	}
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	sum[1] = 0;
	for(int i = 2;i <= n;i++){
		sum[i] = (a[i] - a[i-1]);
	}
	int r = 2,l = 1;
	while(){
		while()
	}
	for(int i = 1;i <= n;i++) cout << sum[i] << " ";
	cout << n << endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
*/
