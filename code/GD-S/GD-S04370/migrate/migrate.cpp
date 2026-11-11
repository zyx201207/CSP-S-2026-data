#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,x[N],ans,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			if(abs(x[i+1]-x[i])<=d&&abs(x[i+2]-x[i])<=d&&abs(x[i+3]-x[i])>d){
				for(int k=3;k<=n-i;k++){
					if(abs(x[i+k]-x[i+1])<=d) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
