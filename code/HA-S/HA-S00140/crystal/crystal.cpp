#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
typedef long long ll;
int n;
ll m;
ll a[N];
ll sum[N];

bool check(int len){
	for(int i = len;i<=n;i++){
		if(a[i]*1ll*len - sum[i] + sum[i-len] <=m){
			return true;
		}
	}
	return false;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		sum[i] = sum[i-1] + a[i];
	}
	int l = 0,r = n+1;
	while(l+1<r){
		int mid = l+(r-l)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	if(check(r)) cout<<r<<'\n';
	else cout<<l<<'\n';
	return 0;
}
