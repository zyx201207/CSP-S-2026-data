#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[1145141*2];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n-3;i++){
			if(x[i+3]-x[i]>d&&x[i+3]-x[i+2]<=d&&x[i+3]-x[i+1]<=d){
				if(x[i+2]-x[i]<=d&&x[i+1]-x[i]<=d){
					ans++;
				}
			}
		}
		cout<<ans<< endl;
	}
}//I love cyq
