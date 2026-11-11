#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],su[500005];
void solve(){
	cin>>n>>m;
	for (int i=1;i<=n;cin>>a[i++]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)su[i]=su[i-1]+a[i];
	
	int ans=1;
	for (int i=1;i<=n;i++){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=l+r>>1;
			if ((i-mid+1)*a[i]-(su[i]-su[mid-1])<=m)res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
//		cout<<i-res+1<<'\n';
	}
	cout<<ans;
}
signed main(){
//	freopen("C:\\Users\\Administrator\\Desktop\\crystal\\crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout); 
	solve();
	return 0;
}
