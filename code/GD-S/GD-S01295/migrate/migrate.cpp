#include<bits/stdc++.h>
using namespace std;
const int N=2e6+3;
#define int long long
int c,T;
int n,d,a[N];
int ans,s1[N],s2[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		for(int i=1; i<=n; i++){
			int x=upper_bound(a+i,a+n+1,a[i]+d)-a-1;
			if(x-i<2)continue;
			int l=upper_bound(a+x+1,a+n+1,a[x-2]+d)-a;
			int r=upper_bound(a+x+1,a+n+1,a[x-1]+d)-a-1;
			if(l>r)continue;
			ans+=r-l+1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
