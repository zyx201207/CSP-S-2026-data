#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
bool cmp(long long x,long long y){
	return x > y;
}
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	vector<long long> p(n + 1,0LL);
	for(int i = 1;i<=n;i++){
		cin >> p[i];
	}
	sort(p.begin() + 1,p.end(),cmp);
	ans = p[1];
	for(int i = 2;i<=m;i++){
		ans = ans & p[i];
	}
	cout << ans;
	return 0;  
}
