//GZ-S00104 贵阳市第一中学 胡源宸 
#include<bits/stdc++.h>
#define ll long long
#define ls i<<1
#define rs i<<1|1
using namespace std;
const int N=5e5+10,L=20;
ll T,n,a[N],sumn[N],m,st[N][L],lg[N],ans;
ll askst(ll l,ll r){
	ll w=lg[r-l+1];
	return max(st[l][w],st[r-(1ll<<w)+1][w]);
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sumn[i]=sumn[i-1]+a[i];
	lg[1]=0;
	for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;i++) st[i][0]=a[i];
	for(int j=1;j<L;j++){
		for(int i=1;i<=n;i++){
			st[i][j]=max(st[i][j-1],st[min(n,i+(1ll<<(j-1)))][j-1]);
		}
	}
	for(int i=1;i<=n;i++){
		ll l=1,r=i,res=i+1;
		while(l<=r){
			ll mid=l+r>>1; 
			if(askst(mid,i)*(i-mid+1)-(sumn[i]-sumn[mid-1])<=m){
				res=mid;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	cin.tie(nullptr);
	freopen("crystal.out","w",stdout);
	T=1;
	while(T--){
		solve();
	}
	return 0;
}
