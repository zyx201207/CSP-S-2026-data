#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000002],xc[2000002],flag=0;
int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			xc[i]=x[i]-x[i-1];
			if(i>=2&&xc[i]!=xc[i-1]){
				flag=1;
			}
		}
		if(!flag){
			if(xc[1]>d){
				cout<<0<<"\n";
			}
		}
	}


	return 0;

}

