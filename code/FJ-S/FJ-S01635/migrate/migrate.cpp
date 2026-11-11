#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int c,t,f=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int a=1;a<=t;a++){
		int n,d;
		cin>>n>>d;
		int x[2000000];
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]==x[i-1]-x[i-2]){
				f*=1;
			}else{
				f*=0;
			}
		}
		if(f==1){
			cout<<n-1<<endl;
		}else{
			cout<<n<<endl;
		}
	}
	return 0;
}
