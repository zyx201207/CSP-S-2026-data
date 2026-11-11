#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 5005
int c,t;
int val[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>val[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(val[j]-val[i]>d||val[j]-val[i]<2*d) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


