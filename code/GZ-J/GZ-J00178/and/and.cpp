//GZ-J00178 观山湖中学 陈辰 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int a[N];
void solve(){
	int n,m,ans=2^31-1;
	cin >>n>>m;
	for (int i = 1;i <= n;i++){
		cin >>a[i]; 
	}
	sort(a+1,a+n+1);
	for (int i = n;i > n-m;i--){
		ans&=a[i];
	}
	cout <<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	//cin >>T;
	while(T--){
		solve();
	}
	return 0;
}
