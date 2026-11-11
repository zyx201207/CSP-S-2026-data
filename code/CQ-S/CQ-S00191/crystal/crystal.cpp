#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],pre[N]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=n-i+1;
		int res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			int pos=i+mid-1;
			if(a[i]*mid-(pre[pos]-pre[i-1])<=m){
				l=mid+1;
				res=mid;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}
