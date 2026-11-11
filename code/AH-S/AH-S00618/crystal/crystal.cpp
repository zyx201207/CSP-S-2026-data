#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+5;
int n,m,a[N],pre[N];
bool check(int l,int r){
	return a[r]*(r-l+1)-(pre[r]-pre[l-1])<=m;
}
signed main(){
	//t1
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(check(mid,i)) r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
	return 0;
} 
