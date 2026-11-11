#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main(){
	freopen("migrate.in ","r",stdin);
	freopen("migrate.out ","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=2;i<n;i++){
			if(x[i+2]-x[i] <= d && x[i+1]-x[i-1] <= d && x[i+2]-x[i-1] > d) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
