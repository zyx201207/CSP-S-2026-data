#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[500000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d>n/2){
			cout<<n/d/2;
		}
		else{
			if(d%2==0){
				cout<<n/d/2;
			}
			else{
				cout<<n/d/2+1; 
			}
		}
		cout<<"\n";
	}
	return 0;
}
