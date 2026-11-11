#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
ll a[N],x=-1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout << a[n];
		return 0;
	}
	for(int i=n;i>n-m;i--){
		x&=a[i];
	}
	cout << x;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	return 0;
} 







