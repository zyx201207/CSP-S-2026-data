#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const int M=5*1e5+10;
ll a[M]={0},w[M],m,n,ans=0,tmp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	tmp = m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		w[i-1] = a[i] - a[i-1];
	}
	sort(a+1,a+n+1);
	if((a[n]-a[1])*(n-1)<=m){
		cout << n;
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		tmp = m;
		int j = i+1;
		while(j<n){
			ll t=tmp-w[j-1]*(j-i);
			if(t<=0) break;
			tmp = t;
			j++;
		}
		if(j-i+1>ans) ans = j-i+1;
	}
	cout << ans;
	return 0;
}
