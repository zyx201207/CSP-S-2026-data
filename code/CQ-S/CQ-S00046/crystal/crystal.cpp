#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pa pair<int,int> 
#define mkp make_pair
#define FI first
#define SE second
int n,m,a[500005],qz[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)qz[i]=qz[i-1]+a[i];
	for(int i=1,l,r,mid;i<=n;i++){
		l=1;
		r=i;
		while(l<r){
			mid=l+r>>1;
//			cout<<l<<' '<<r<<' '<<mid<<"\n";
			if(a[i]*(i-mid+1)-(qz[i]-qz[mid-1])<=m){
				r=mid;
			}else l=mid+1;
		}
//		cout<<i<<" "<<l<<'\n';
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
