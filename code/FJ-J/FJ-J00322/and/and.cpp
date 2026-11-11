#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int maxn=2e5+10;
int n, k;
LL a[maxn], pow2[maxn], ans=0;
bool bxz[maxn];
/*void out(LL x){
	vector <int> sm;
	while(x>0){
		sm.push_back(x%2);
		x>>=1;
	}
	for(int i=sm.size()-1;i>=0;i--){
		cout << sm[i];
	}
	return ;
}*/
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++)cin >> a[i];
	/*for(int i=1;i<=n;i++){
		out(a[i]);
		cout << '\n';
	}*/
	pow2[0]=1;
	for(int i=1;i<=31;i++){
		pow2[i]=pow2[i-1]*2;
	}
	for(int LOG=30;LOG>=0;LOG--){
		int cnt1=0;
		for(int i=1;i<=n;i++){
			if(bxz[i])continue;
			if((a[i]>>LOG)&1)cnt1++;
		}
		if(cnt1>=k){
			ans+=pow2[LOG];
			for(int i=1;i<=n;i++){
				if(bxz[i])continue;
				if(((a[i]>>LOG)&1)!=1)bxz[i]=true;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
5 3
31 3 1 15 7

*/
