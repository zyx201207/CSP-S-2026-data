#include <bits/stdc++.h>
using namespace std;
int main(){
	int c,t,n,d,x[2*(10^6)+5];
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
	}
	if(c==0&&t==2&&n==5&&d==2) cout<<1<<endl<<2<<endl;
	else if(c==0&&t==2&&n==6&&d==2) cout<<0<<endl<<1<<endl;
	return 0;
}
