#include<bits/stdc++.h>
using namespace std;
long long q,t,n,m,a[200005]={0};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>q>>t;
	while(t--){
		int ans=0;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n-3;i++){
			if(a[i]+m<a[i+3]&&(abs(a[i+1]-a[i+3])<=m||abs(a[i+2]-a[i+3])<=m)){
				ans++;
			}
		}
		cout<<ans<<endl;
		for(int i=0;i<n;i++){
			a[i]=0;
		}
	}
	return 0;
}
