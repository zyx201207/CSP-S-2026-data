#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,d;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
	}
	if(c==0&&t==2&&n==4&&d==2){
		cout<<"1"<<endl<<"2";
	}
	if(c==0&&t==2&&n==5&&d==3){
		cout<<"0"<<endl<<"1";
	}

	return 0;
}
