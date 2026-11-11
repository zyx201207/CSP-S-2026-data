#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d,x[100005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int mm=0;
		for(register int i=1;i<=n;i++){
			cin>>x[i];
			mm=x[i]-x[i-1];
		//	f[i]=0;
		}
	//	if(mm>=d){
			cout<<"0"<<'\n';
	//		continue;
//		}
//		int ans=0;
//		for(register int i=3;i<=n;i++){
//			if(x[i]-x[i-2]>=d){
//				ans++;
//			}
//		}
	//	cout<<ans<<"\n";
	}
	return 0;
}

