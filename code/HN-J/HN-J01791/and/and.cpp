#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
using ll=long long;
ll n, m, a[N], mx,k, ans, ljw, j;
ll kk(ll x, ll y){
	return x>=y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ljw=a[1];
	if(n==m){ 
		for(int i = 2; i <= n; i++){
			ljw&=a[i];
		}
		cout << ljw;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i = 1, j = 1; i <= n-m+1; j++){
		if(j==1) ljw=a[j];
		ljw&=a[j];
		if(j==i+m-1){
			mx=max(mx,ljw);
			i++;
			j=i;
			ljw=a[j];
		}
	}
	cout << mx;
	return 0;
}

