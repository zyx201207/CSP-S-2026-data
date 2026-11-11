#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;

//crystal

int n;
long long m;
long long a[MAXN],pre[MAXN];
struct node {
	long long l,r,val;	
}tot[MAXN];

bool cmp(node x,node y) {
	return x.val < y.val;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	long long ans = 0;
	for(int i = 1;i <= n;i++) {
		if(i != 1) tot[i - 1].l = i - 1,tot[i - 1].r = i,tot[i - 1].val = a[i] - a[i - 1]; 
		pre[i] = pre[i - 1] + (i - 1) * (a[i] - a[i - 1]);
		if(pre[i] <= m) ans = i;
	}
	sort(tot + 1,tot + n,cmp);
	int pop = 1;
	int k = 0;
	for(int i = 1;i < n;i++) {
		if(tot[i].l == 1) {
			k = i;
			break;
		}
	}
	while(tot[pop].l + ans - 1 >= n) {
		pop++;
		if(pop == k) break;
	}
	if(pop == k) {
		cout << ans << '\n';
		return 0;
	}
	ans = 0;
	memset(pre,0,sizeof pre);
	for(int i = tot[pop].l;i <= n;i++) {
		pre[i] = pre[i - 1] + (i - tot[pop].l) * (a[i] - a[i - 1]);
		if(pre[i] <= m) ans = i;
	} cout << ans - tot[pop].l + 1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

