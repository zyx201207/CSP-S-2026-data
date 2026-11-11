#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000001];
bool pd(long long x,long long y){
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (pd(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
