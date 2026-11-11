#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+7;
long long c,n,t;
long long d,x[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int dx=x[2]-x[1];
		if(d/dx<2){
			cout<<0<<endl;
			continue;
		}
		else{
			long long ans=0;
			cout<<max(ans,n-(2*(d/dx)-1))<<endl;
			continue;
		}
	}
	return 0;
} 
