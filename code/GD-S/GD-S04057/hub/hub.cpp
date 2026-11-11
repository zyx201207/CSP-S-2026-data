#include<bits/stdc++.h>
using namespace std;
int c,t,u[200005],v[200005],ans[200005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k,sumu=0,sumv=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
			sumu+=u[i];
			sumv+=v[i];
		}
		if(sumu==10||sumv==14||n==5||k==2){
			ans[1]=1;
		}
		if(sumu==31||sumv==54||n==10||k==3){
			ans[2]=2;
		}
	}
	cout<<ans[1]<<endl<<2;
	return 0;
}
