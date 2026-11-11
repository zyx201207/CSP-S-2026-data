#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,a[2000005];
//void solve(int t){
//	cin>>n>>d;
//	for(int i=0;i<=n;i++)cin>>a[i];
//    
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(2*abs(a[2]-a[1])<=d){
			int ans=0;
			for(;n>=4;n--){
				ans+=n/2-1;
			}
			cout<<ans<<'\n';
		}	
		else cout<<"0\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}