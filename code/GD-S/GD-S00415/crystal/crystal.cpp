#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n;
ll m, a[N];
ll minx = LLONG_MAX;
void find_l(){
	sort(a + 1,a + 1 + n);
	a[1]++;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= m;i++){
		find_l();
	}
	int cnt = 1;
	for(int i = 2;i <= n;i++){
		if(a[i] == a[i - 1]) cnt++;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
