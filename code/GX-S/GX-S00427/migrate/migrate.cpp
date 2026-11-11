#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,p[2000008],d1,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>p[i];
		}
		if(c==1||c==2){
			cout<<0<<'\n';
		}else{
			ans=0;
			d1=p[2]-p[1];
			
			for(int i=3;i<=n;i++){
					if(d1*(i-2)<=d&&d1*(i-1)>d){
						ans+=(p[n]-p[1])/d1;
						ans-=(i-2);
					}
			}
			cout<<ans<<'\n';
		}
	}

	return 0;
}
