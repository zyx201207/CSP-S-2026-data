#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,xx[200005],ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>xx[i];
		}
		cout<<ans;
	}
	return 0;
}
