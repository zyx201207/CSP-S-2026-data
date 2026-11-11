#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10;
int n,m,cnt,ans,a[N],pre[N];

signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;i+j<=n;j++){
			if(a[i+j]==a[i]) cnt++;
			else break;
		}
		int l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid)-(pre[i-1]-pre[mid-1])<=m) r=mid-1;
			else l=mid+1;
		}
		cnt+=i-r;
		ans=max(ans,cnt);
	}
	cout<<ans;
}
