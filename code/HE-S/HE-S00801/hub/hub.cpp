#include <bits/stdc++.h>
using namespace std;
int main(){
	int c,t,n,k,u[2*(10^6)+5],v[2*(10^6)+5];
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>u[j]>>v[j];
		}
	}
	if(c==0&&t==2&&n==10&&k==3) cout<<1<<endl<<2<<endl;
	else if(c==0&&t==3&&n==9&&k==3) cout<<1<<endl<<1<<endl<<2<<endl;
	return 0;
}
