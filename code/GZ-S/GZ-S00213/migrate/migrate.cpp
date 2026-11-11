//遵义市第四中学 陈文涛 GZ-S00213
#include <bits/stdc++.h>
using namespace std;

long long c,t,n,d,a[200004],ans;

struct fly{
	long long kind;
	long long need;
};fly dp[200004];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int j=1;j<=t;j++){
        ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}dp[1].kind=1;
		int l=1,r=2;
		while(l<n){
			while(a[r]-a[l]<=d){
				if(a[r]-a[l]>=dp[l].need){
					dp[r].kind+=dp[l].kind;
					dp[r].need+=d-(a[r]-a[l]);
				}
				if(dp[r].kind==2)ans++;
				r++;
			}l++;
		}cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}



