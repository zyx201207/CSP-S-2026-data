#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int res[500005],pre[500005];
int cnt=0;
bool check(int x){
	int cnt=0,lst=0;
	for(int i=1;i<=n;i++){
		if(i<x)cnt+=a[i];
		else{
			cnt+=a[i];
			cnt-=a[lst];
			cnt=a[i]*x-cnt;
			if(cnt<=m)return 1;
			cnt=a[i]*x-cnt;
			lst++;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		res[i]=res[i-1]+a[i]-a[i-1];
		if(a[i]!=a[i-1])pre[i]=pre[i-1]+res[i];
		else pre[i]=pre[i-1];
		//cout<<res[i]<<" "<<pre[i]<<endl;
	}
	int l=1,r=n;
	int ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
