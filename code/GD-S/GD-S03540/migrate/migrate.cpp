#include<bits/stdc++.h>
using namespace std;
int x[100005],y[100005];
int vis[100005]={0};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long n,d,c,t,ans=0;
	cin>>n>>d>>c>>t;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if((x[i]-y[i])*(x[i]-y[i])<=d){
				ans++;
			}
		}
	}
	cout<<ans;
	
	
	return 0;
}
