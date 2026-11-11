#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000009],i,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(i=1;i<=n;i++){
			cin>>a[i];
			if(d<2*(a[i+1]-a[i]))ans=0;
			else{
				if(n<4)ans=0;
				if(n>=4)ans=n-3;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
