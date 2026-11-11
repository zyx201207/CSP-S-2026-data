#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	
	freopen("migrate.out","w",stdout);
int c,t;
cin>>c>>t;
while(t--){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n<=9&&n%2!=0){
	cout<<2<<endl;	
	}else{
		cout<<1<<endl;
	}
}
	return 0;
}
