#include<bits/stdc++.h>
#define x first
#define y second
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout) 
using namespace std;
typedef pair<int,int> pii;
int n,a[500005],m,s[500005];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	fre("crystal");
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	int ans=0;
	rep(i,1,n){
		int l=1,r=i,id=-1;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m) id=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-id+1);
	} 
	cout<<ans;
} 
