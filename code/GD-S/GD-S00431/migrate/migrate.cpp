#include<bits/stdc++.h>
using namespace std;
long long x[500001],c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		long long n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d/2>=0){
			ans+=d/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
