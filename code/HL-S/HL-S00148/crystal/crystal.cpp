#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[600010],ans,t,s[600010];
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int sa=i+x-1;
		if((s[sa]-s[i]-(i-1)*(a[sa]-a[i]))<=m){
			return true;
		}
	}
	return false;
}
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
	sort(a+1,a+1+n);
	s[1]=0;
		for(int i=2;i<=n;i++){
			s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
			//cout<<s[i]<<" ";
		}
		int l=0,r=n+1,ans=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)){
				l=mid+1;
				ans=mid;
			}
			else{
				r=mid-1;
			}
		}
		cout<<ans;
	return 0;
}
