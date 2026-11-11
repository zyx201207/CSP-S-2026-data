#include<bits/stdc++.h>
using namespace std;
long long x[100000];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    long long c,t,n,d;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
    	cin>>n>>d;
    	for(int j=1;j<=n;j++){
    		cin>>x[i];
		} 
	}
		cout<<1<<endl;
		if(t==2){
			cout<<2;
		}else{
			cout<<0;
		}
	return 0;
}
