//GZ-S00325 贵阳市南明区华麟学校 陈锦江
#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if((x[2]-x[1])*2<=d){
			cout<<n-3<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}

