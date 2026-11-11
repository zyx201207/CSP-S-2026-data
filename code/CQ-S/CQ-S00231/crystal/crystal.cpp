#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
int n;
long long m,a[N];
bool check(int k){
	int l=k+1;
	long long mi=2e18,sum=0;
	for(int i=1;i<=k;i++) sum+=a[i];
	mi=min(mi,k*a[k]-sum);
	for(int i=l;i<=n;i++){
		sum+=a[i]-a[i-k];
		mi=min(mi,k*a[i]-sum);
	}
	return mi<=m;
}
int ef(int l,int r){
	while(l<=r){
		int mid=l + r >> 1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cout<<ef(1,n); 
	return 0;
} 
