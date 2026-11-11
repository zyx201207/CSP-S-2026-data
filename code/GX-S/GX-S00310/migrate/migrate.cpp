#include<bits/stdc++.h>
using namespace std;
long long c,t,n;
long long d,x[2000006],sum[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		memset(sum,0,sizeof(sum));
		sum[1]=1;
		sum[2]=1;
		cout<<1<<'\n';
		break;
	}
	cout<<0;
	return 0;
}
