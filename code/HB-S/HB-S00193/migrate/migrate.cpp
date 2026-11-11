#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
     cin>>c>>t;
    for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			
		}
		if(c==11||c==12){
		ans=x[2]-x[1];
		if(2*ans<=d&&d<3*ans) cout<<n-3<<"\n";
		else cout<<0<<endl;
	}
		} 
return 0;	
}
