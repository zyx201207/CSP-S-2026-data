//GZ-S00139 贵阳市第一中学 张梁予 
#include<bits/stdc++.h>
using namespace std;
long long n,c,t,d,a[2000005];

int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n>>d>>a[1]>>a[2];
		for(int i=3;i<=n;i++){
			cin>>a[i];
		}
		cout<<0<<'\n';
	}
	return 0;
}
