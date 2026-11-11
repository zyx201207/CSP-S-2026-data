#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll aa[N],sum[N],j,s;
bool cmp(int x,int y){
	return x<y;
}
bool check(ll x){
	for(int i=1;i+x-1<=n;i++){
		j=i+x-1;
		s=aa[j]*x-(sum[j]-sum[i-1]);
		if(s<=m)return 1;
	}
	return 0;	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>aa[i];
	}sort(aa+1,aa+n+1,cmp);
	//二分找长度
	ll l=1,r=n,ans=1,mid;
	//前缀和优化计算点数 
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+aa[i];
	}
	while(l<=r) {
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=max(mid,ans);
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
