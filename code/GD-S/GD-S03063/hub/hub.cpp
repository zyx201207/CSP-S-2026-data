#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[1000005],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
		bool f=0;
		for(int m=1;m<=1000005;m++){
			for(int i=1;i<=n;i++){
				if(u[i]!=i && v[i]!=i+1 || u[i]!=i-m && v[i]!=i+1){
					f=1;
				}
			}
			if(f==0 && n==2*m+1){
				cout<<m<<endl;
				break;
			}
		}
		if(f==0){
			continue;
		}
		if(n<=5){
			cout<<"1"<<endl;
			continue;
		}
	}
	return 0;
} 
