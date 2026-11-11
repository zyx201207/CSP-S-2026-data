#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		if(n%d>=2){
			cout<<"0"<<endl;
		}
		else cout<<n/d<<endl;
	}
	//cout<<"1 2"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
