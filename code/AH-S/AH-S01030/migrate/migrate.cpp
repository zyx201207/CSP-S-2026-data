#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,b[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
		if(n==1||n==2||n==3){
			cout<<0<<endl;
			continue;
		} 
		long long dc=b[2]-b[1];
		if(d<dc){
			cout<<0<<endl;
			continue;
		}
		long long s=d/dc;
		if(s==1){
			cout<<0<<endl;
			continue;
		}
		if(n-s*2+1<0) cout<<0<<endl;
		else cout<<n-s*2+1<<endl;
	}
    return 0;
}
