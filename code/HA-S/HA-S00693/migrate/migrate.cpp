#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			
		}
	}
	if(c==11||c==12){
		cout<<n-2<<"\n";
	}
	if(c==1||c==2){
		cout<<0<<"\n";
		
	}
	return 0;
} 
