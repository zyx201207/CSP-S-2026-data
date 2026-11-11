#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n;
long long m, a[N];
struct node {
	long long x, y, z;
} ans[N];
bool cmp1(node aa, node bb) {
	return aa.y < bb.y;
}

bool cmp2(node aaa, node bbb) {
	return aaa.z < bbb.z;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	ans[i].x = a[i];
    	ans[i].y = abs(a[i]);
	}
	
	sort(ans + 1, ans + n + 1, cmp1);
	
	int l, j = 1, sum = 0;
	if(n % 2 == 0) l = n / 2;
	else l = n / 2 + 1;
	
	for(int i = 1; i <= n; i++) {
		ans[i].z = abs(ans[l].x - ans[i].x);
	}
	sort(ans + 1, ans + n + 1, cmp2);
	while(1) {
		m -= ans[j].z;
		if(m < 0) break;
		j++;
		sum++;
	}
	
	cout << sum;
	return 0;
} 
