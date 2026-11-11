#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int x[2000005];
int pre[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i!=1)pre[i]=pre[i-1]+x[i]-x[i-1];
		}
		for(int i=n;i>=1;i--){
			if(pre[i]-pre[i-1]<=d&&pre[i]-pre[i-2]<=d
			&&pre[i-1]-pre[i-2]<=d&&pre[i-1]-pre[i-3]<=d
			&&pre[i-2]-pre[i-3]<=d&&pre[i]-pre[i-3]>d){
				ans++;
				for(int j=i-4;j>=1;j--){
					if(pre[j+2]-pre[j]>d&&pre[j+1]-pre[j]<=d){
						ans++;
					}
					else{
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
