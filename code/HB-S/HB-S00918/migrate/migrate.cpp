#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans;
int x[200010];
int a[200010];
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
		a[1]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(x[i]-x[j]<=d){
					if(a[i]==0){
						a[i]=a[j];
					}else{
						a[i]=max(a[i],a[j]+1);
					}
				}
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]==2){
					ans+=1;
				}
			}
		}
		cout<<ans-1;
	}
	return 0;
}
