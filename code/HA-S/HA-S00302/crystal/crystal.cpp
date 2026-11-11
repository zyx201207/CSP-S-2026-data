#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int Tc=1,n,m,a[N],s[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		int sum=s[i]-s[i-x];
		if(a[i]*x-sum<=m)return 1;
	}
	return 0;
}
void solve(int cs){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,res=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			res=mid;
		}
		else r=mid-1;
	}
	cout<<res<<'\n';
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	cin>>Tc;
	for(int cs=1;cs<=Tc;cs++){
		solve(cs);
	}
	return 0;
}
