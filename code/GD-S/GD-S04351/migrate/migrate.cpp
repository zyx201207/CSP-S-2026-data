#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N]; 
int ans=0;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		ans=0;
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<1<<endl;
		int d0=x[2]-x[1];
		int maxd=d/d0;
		for(int i=maxd+1;i<maxd*2;i++){
			ans+=(x[n]-x[i+1])/d0+1;
		} 
		cout<<ans<<endl;
	}
	return 0;
}

