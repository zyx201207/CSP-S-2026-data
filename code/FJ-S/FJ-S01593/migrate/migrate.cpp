#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10; 
int c,t;
int x[N];
int n,d;
int ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n-3;i++){
			if((x[i+2]-x[i])<=d&&(x[i+3]-x[i])>d&&x[i+3]-x[i+1]<=d){
				ans++;
				for(int j=1;j<=n-i;j++){
					if(x[i+3+j]-x[i+1+j]>d&&x[i+3+j]-x[i+2+j]<=d&&x[i+2+j]-x[i+1+j]<=d)
					ans++;
					else{
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

