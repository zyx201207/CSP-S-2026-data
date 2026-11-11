#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,m,a[1000005],k,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;k=1;ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			while(i<=n){
				while(k<=n&&a[k]-a[i]<=m) k++;
				if(k>n) break;
				if(a[k]-a[i+1]>m) i++;
				else break;
			}
			if(i>n||k>n) break;
			if(k-i==3) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
