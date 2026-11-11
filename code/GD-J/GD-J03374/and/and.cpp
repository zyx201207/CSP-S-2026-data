#include <bits/stdc++.h>
using namespace std;
int n,m,maxn = -199;

int a[20000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n >>m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxn = max(maxn,a[i]);
	}
	
	if(m==1){
		cout << maxn;
		return 0;
	}
	return 0;
}
