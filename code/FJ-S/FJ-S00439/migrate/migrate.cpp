#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,s[2000001],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		
		for(int i=1;i<=n;i++){
			if(i+2*d-1<=n){
				ans+=1;
			}
			if(i+d+1<=n&&i+2*d-1!=i+d+1){
				ans+=1;
			}
		}
		cout<<ans<<endl;}
	return 0;
}
