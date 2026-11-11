#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 500005;
int n;
ll m;
ll a[maxn];
ll d[maxn];
ll summ[maxn];
int sum = 0;
int maxx = 0;
int x = 0;
int l = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	l = 1;
	for(int r = 1; r < n; r++){
		d[r] = a[r + 1] - a[r];
		x = r - l + 1;
		sum += d[r] * x;
		while(sum > m){
			sum -= a[r + 1] - a[l];
			l++;
		}
		x = r - l + 1;
		maxx = max(maxx, x);
	} 
	cout << maxx + 1;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
