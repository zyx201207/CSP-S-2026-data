//GZ-S00081 六盘水市第二十四中学 周启明 
#include <bits/stdc++.h>
using namespace std;

long long n,m,x,ma,l,r;
vector<long long> c,sc,sum;
bool f;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long a[n + 1];
	a[0] = 0;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}if (m == 0){
		cout << 1;
		return 0;
	}sort(a + 1,a + n + 1);
	c.push_back(0);
	sc.push_back(0);
	c.push_back(0);
	sc.push_back(0);
	sum.push_back(0);
	sum.push_back(a[0]);
	for (int i = 2;i <= n;i++){
		c[i] = a[i] - a[i - 1];
		sc[i] = (i - 1) * c[i] + sc[i - 1];
		sum[i] = sum[i - 1] + a[i];
	}for (int i = 3;i <= n;i++){
		if (c[i] != c[i - 1]){
			f = 1;
		}
	}if (!f){
		l = 1;
		while (sc[l] <= m){
			l++;
		}cout << l - 1;
		return 0;
	}ma = l = r = 1;
	while (r < n){
		if (sc[r] - a[r] * (l - 1) + sum[l - 1] <= m){
			if (ma < r - l + 1){
				ma = r - l + 1;
			}r++;
		}else if (l < r){
			l++;
		}else{
			r++;
		}
	}cout << ma;
	return 0;
}

