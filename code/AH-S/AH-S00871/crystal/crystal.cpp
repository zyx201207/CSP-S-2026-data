#include<bits/stdc++.h>
using namespace std;
const int MaxN=5e5+5;
long long a[MaxN];
long long c[MaxN];
long long add(int i,int j){
	return a[j]*(j-i+1)-(c[j]-c[i-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	long long n,m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	int l=1,r=1;
	int ans=0;
	while(r<=n){
		long long sum=add(l,r);
		if(sum<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
