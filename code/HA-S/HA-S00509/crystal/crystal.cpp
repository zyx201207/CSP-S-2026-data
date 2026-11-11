#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x > y;
}
int a[500005],n,m,summ,maxx = -1,i = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	int ns = n;
	while(ns){
		int f = m,ans = 0,p = 0;
		while(p <= ns){
			p++;
			f -= a[ns] - a[ns - p];
			ans++;
			if(f < 0){
				break;
			}
		}
		maxx = max(maxx,ans);
		ns--;
	}
	cout << maxx;
	return 0;
}