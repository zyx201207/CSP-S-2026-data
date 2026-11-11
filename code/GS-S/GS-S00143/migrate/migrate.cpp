#include <bits/stdc++.h>
using namespace std;
int t,k;
int n,d,a[2000500];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>k>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int fly=a[2]-a[1];
		int far_fly=d/fly;
		for(int i=n;i>=4;i--){
			int jili=0;
			if(i>far_fly){
				if(i%far_fly==0)  jili=i/far_fly;
				else{
					jili=i/far_fly+1;
					if(jili==2) ans++;
					
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
