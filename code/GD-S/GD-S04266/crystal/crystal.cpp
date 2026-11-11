#include<bits/stdc++.h> 
#define ll long long
#define maxn 500005
using namespace std;
ll n,m,a[maxn],sum[maxn];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int res=1;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++){
//			ll dt=a[i]*(i-j)-(sum[i-1]-sum[j-1]);
////			cerr<<dt<<"\n";
//			if(dt<=m){
//				res=max(res,i-j+1);
//			}
//		}
//	}
	int l=1;
	for(int r=1;r<=n;r++){
		ll cnt=(r-l)*a[r]-(sum[r-1]-sum[l-1]);
		if(cnt<=m)res=max(res,r-l+1);
		else l++;
	}
	cout<<res<<"\n";
	return 0;
}
