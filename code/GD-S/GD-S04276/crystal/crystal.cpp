#include<bits/stdc++.h>
using namespace std;
#define int long long
bool st;
const int N=5e5+5;
int n,m,ans;
int a[N],pre[N];
bool ed;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	cerr<<(&st-&ed)/1024.0/1024.0;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m){
				res=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
}
