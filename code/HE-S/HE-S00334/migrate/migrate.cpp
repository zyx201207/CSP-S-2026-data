#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		vector<int> a(n+5);
		for(int i=1;i<=n;i++) cin>>a[i];
		int cha=a[2]-a[1];
		int sum=d/cha;
		int ans=0;
		for(int i=1;i<=sum;i++){
			int k=n-i-1;
			ans+=(k+1)*k/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}

