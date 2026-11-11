#include<bits/stdc++.h>
#define endl "\n"
#define int long long 
using namespace std;
int n,m;
int a[500010];
int s[500010];
bool check(int len){
	for(int l=1;l+len-1<=n;l++){
		int r=l+len-1;
		int sum1=s[r]-s[l-1];
		if(len*a[r]-sum1<=m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
