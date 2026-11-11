#include <bits/stdc++.h>
using namespace std;
int n,m,mx;
vector<int> a(n);
void yu(int x,int s,int b){
	if(x > n) return;
	if(s == b) mx = max(x&s + 1&b,x & s -1 & b);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i <= n; i++){
		cin >> a[i];
	}
	yu(-1,0,1);
	cout << mx;
	return 0;
}
