#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,d,a[2000005],ans;
int main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin >>t>>t;
	while(t--){
		cin >>n>>d,ans=-1e18;
		for(int i=1;i<=n;i++) cin >>a[i],ans=min(ans,a[i]-a[i-1]);
		if(n==1 || n==2 || ans>d){cout<<"0";continue;}
		ans=0;
		
	}
	return 0;
}
