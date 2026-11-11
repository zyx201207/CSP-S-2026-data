#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],sum[N];
bool check(int l,int r){
	long long len=r-l+1;
	if((len*a[r]-(sum[r]-sum[l-1]))<=m) return true;
	else return false;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)==true){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}
		maxx=max(maxx,i-ans+1);
	}
	cout<<maxx<<"\n";
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
