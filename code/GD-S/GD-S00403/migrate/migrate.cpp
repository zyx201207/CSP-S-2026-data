#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
int a[500050],b[500050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			b[i]=a[i]-a[i-1];
		}
		for(int i=2;i<=n;i++){
			if(b[i]<m){
				ans+=b[i];
			}
			if(b[i]<m&&i-1>3&&ans>m&&ans<2*m){
				ans=0;
			}
		}
		cout<<ans/m<<endl;
	}
	return 0;
}

