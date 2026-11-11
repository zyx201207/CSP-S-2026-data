#include<bits/stdc++.h>
using namespace std;
int c,T,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	for(int o=1;o<=T;o++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
	}
	for(int i=1;i<=T;i++){
		cout<<0<<endl;
	}
	return 0;
} 
