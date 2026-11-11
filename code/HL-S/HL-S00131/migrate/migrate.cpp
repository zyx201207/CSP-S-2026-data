#include<bits/stdc++.h>
using namespace std;
int x[2000005],u[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,n,t,d,ans=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
	}
	for(int j=1;j<=t;j++){
		for(int i=1;i<=n;i++){
			if(x[i]-x[i-1]>d){
				u[i]=0;
			}
			if(x[i]-x[i-1]==d){
				u[i]=1;
			}
			if(x[i]-x[i-1]<d){
				u[i]=2;
			}
			if(u[i]==2){
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
