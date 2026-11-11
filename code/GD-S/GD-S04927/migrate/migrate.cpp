#include<bits/stdc++.h>
using namespace std;
long long c,t,n,x[1000],d,bj[1050][1050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		x[n+1]=LONG_LONG_MAX;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long js=0;
		for(int i=1;i<=n-3;i++){
			if(x[i+1]-x[i]<=d&&x[i+2]-x[i]<=d&&x[i]&&x[i+3]-x[i+1]<=d&&x[i+3]-x[i+2]<=d){
				js++;
			}
		}
		cout<<js<<endl;
	}
	return 0;
}
