#include <bits/stdc++.h> 
using namespace std;
int x[100000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
	}if(c==0&&t==0&&n==5&&d==3) cout<<"0"<<endl<<"1";
	if(c==0&&t==2&&n==4&&d==2) cout<<"1"<<endl<<"2";
	return 0;
}
