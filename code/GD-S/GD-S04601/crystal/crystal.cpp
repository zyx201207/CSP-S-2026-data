#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+3;
int n,m;
ll a[N];
ll qh[N],qh2[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%d",&n, &m);
	scanf("%lld", &a[1]);
	for(int i=2; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2; i<=n; i++){
		qh[i]=qh[i-1]+a[i]-a[i-1];
		qh2[i]=qh[i]+qh2[i-1];
	}
	ll l=1, r=2, ans=0, cnt=qh[2];
	while(r<=n){
		if(l==r){
			r++;
			continue;
		}
		
		cnt=qh[r]*(r-l)-(qh2[r-1]-qh2[l-1]);
		
		if(cnt<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else	l++;
	}
	printf("%lld\n", ans);
	return 0;
}
