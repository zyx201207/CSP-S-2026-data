#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define N 500005
ll n,m;
ll a[N],b[N];
ll sum[N],pre[N];
ll ans=0;
bool check(int i,int j){
	int t=sum[j-1]*(j-i);
	t-=(pre[j-2]-pre[i-1]);
	if(t<=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++) sum[i]=sum[i-1]+b[i];
	for(int i=1;i<n;i++) pre[i]=pre[i-1]+sum[i];
	for(int i=2;i<=n;i++){
		ll l=1,r=i,res=i;
		while(l<=r){
			int mid=l+r>>1; 
			if(check(mid,i)){
				r=mid-1;
				res=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
//freopen
//feropen
