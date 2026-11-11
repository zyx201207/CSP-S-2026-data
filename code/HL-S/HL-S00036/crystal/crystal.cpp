#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N];
int l=0,r=500001,mid;
inline bool check(int len){
	for(int i=1;i<=n-len+1;i++){
		int k=a[i+len-1]*(len-1)-s[i+len-2]+s[i-1];
		if(k<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	while(l+1<r){
		mid=l+r>>1;
		if(check(mid)) l=mid;
		else           r=mid;
	}
	cout<<l;
	return 0;
}