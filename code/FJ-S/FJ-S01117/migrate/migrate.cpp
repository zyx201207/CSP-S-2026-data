#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
		cin>>a[i];
		}for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[j]-a[i])%d!=0&&(a[j]-a[i])!=1&&(a[j]-a[i])>d){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
