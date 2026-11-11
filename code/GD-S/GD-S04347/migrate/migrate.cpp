#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,a[2222222];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c>=0){
			ll maxt=0;
			for(int i=n;i>0;i--){
				if(d>=i*(a[2]-a[1])){
					maxt=i;
					break;
				}
			}
			ll cnt=0;
			if(maxt=2){
				//cnt+=n-3;
				for(int l=3;l<=n;l++){
					if(l%2==1){
						cnt+=n-l;
					}
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
} 
