//GZ-S00329 何子文 遵义市第二中学 
#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[1000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		int zuixiao=x[n]-x[1];
		
		if(zuixiao<=d){
			cout<<0<<endl;;
		}else{
			cout<<zuixiao/d<<endl;
		}
		
	}

	fclose(stdin);
	fclose(stdout);
}

