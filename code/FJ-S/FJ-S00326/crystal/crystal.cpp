#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ma=-1,ans=-1,l,r;
int a[N],d[N];
bool check(int x){
	int cnt=0,sum=0;
	for(int i=x-1;i>=1;i--){
		sum+=a[x]-a[i];
		cnt++;
		if(sum>m&&cnt-1>=ans){
			ans=cnt-1;
			return true;
		}else if(sum==m&&cnt>=ans){
			ans=cnt;
			return true;
		}
	}
	if(cnt>=ans){
		ans=cnt;
		return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	cout<<ans+1;
	return 0;
}
