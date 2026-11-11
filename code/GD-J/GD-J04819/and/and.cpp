#include<bits/stdc++.h>
using namespace std;
map<int,int> d;
const int N = 2e5 + 5;
int a[N];
void cw(int x){
	int i = 1;
	while(x != 0){
		if(x % 2 == 1){
			d[i]++;
		}
		i++;
		x >>= 1;
	}
}
bool zgy(int x,int y){
	int i = 0;
	while(x != 0){
		i++;
		if(i == y && x % 2 == 1){
			return true;
		}
		x >>= 1;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n = 0,m = 0,bj = -1,bj1 = 0;
	cin >> n >> m;
	if(m == 0){
		cout << 0;
		return 0;
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = 0; i < n; i++){
		cw(a[i]);
	}
	for(int i = 0; i < 33; i++){
		if(d[i] >= m){
			bj = i;
		}
	}
	if(bj == -1){
		cout << 0;
		return 0;
	}
	for(int i = 0; i < n; i++){
		if(zgy(a[i],bj)){
			bj1 = i;
		}
	}
	int ans = a[bj1];
	for(int i = bj1; i > bj1 - m; i--){
		ans &= a[i];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
