#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5; 
int n,m;
int a[N],s[N];
bool chk(int p){
	for(int i=p;i<=n;i++){
		int sum=s[i]-s[i-p];
		if(a[i]*p-sum<=m){
			return true;
		}
	}
	return false;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	} 
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
