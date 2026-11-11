#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
const int N=1e6;
int a[N];
void solve(){
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=4;i<=n;i++){
		if(a[i]-m<=a[i-2]&&a[i]-m>a[i-3]){
			int b=a[i-1]-m;
			int loc=lower_bound(a+1,a+n+1,b)-a;
			ans+=i-2-loc;
			
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
