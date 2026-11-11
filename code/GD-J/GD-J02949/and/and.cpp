#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector <long long> a(n+5),b(n+5);
	bool flag = true;
	for (int i=0;i<n;i++){
		cin >> a[i];
		b[i] = a[i];
		if (a[i] > 4) flag = false;
	}
	if (flag){//ai<4
		int cnt_1 = 0;
		int cnt_3 = 0;
		int cnt_2 = 0;
		for (int i=0;i<n;i++){
			if (a[i] == 1) cnt_1++;
			else if (a[i] == 3) cnt_3++;
			else if (a[i] == 2) cnt_2++;
		}
		if (cnt_3 >= m) cout << 3 << '\n';
		else if (cnt_2 + cnt_3 >= m) cout << 2 << '\n';
		else if (((cnt_1 + cnt_3) >= m)|| ((cnt_1 + cnt_2) >= m)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	else if (m == 1){//m==1
		int cnt = -0x3f3f3f3f;
		for (int i=0;i<n;i++){
			if (a[i] > cnt) cnt = a[i];
		}
		cout << cnt << '\n';
	}
	else if (m == n){//m==n
		int ans2 = a[0];
		for (int i=1;i<n;i++){
			ans2 &= a[i];
		}
		cout << ans2 << '\n';
	}
	else if (m == 2){//m==2
		int ans1 = -0x3f3f3f3f;
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				if ((a[i]&a[j]) > ans1) ans1 = (a[i]&a[j]);
			}
		}
		cout << ans1 << '\n';
	}
	else if (m == n-1){//m==n-1
		int cnt3 = 0,ans3 = -0x3f3f3f3f;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (j == i) continue;
				if (cnt3 == 0) cnt3 = a[j];
				cnt3 &= a[j];
			}
			ans3 = max(ans3,cnt3);
			cnt3 = 0;
		}
		cout << ans3 << '\n';
	}
	else{//ai==2^ki-1; 
		sort(b.begin(),b.end(),greater<int>());
		cout << b[m-1] << '\n';
	}
	return 0;
}
