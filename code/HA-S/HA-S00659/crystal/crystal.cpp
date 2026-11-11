#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int qh[N];
int m;
bool check(int l,int r,int x){
	int res=qh[r]-qh[l-1];
	res=x*(r-l+1)-res;
	return res<=m;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) qh[i]=qh[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid,i,a[i])) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
		//cerr<<i<<" "<<l<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
