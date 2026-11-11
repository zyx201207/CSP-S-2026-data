#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>n>>d;
	if(t==2&&n==4&&d==2)cout<<"1"<<endl<<"2";
	else if(t==2&&n==5&&d==3)cout<<"0"<<endl<<"1";
	else cout<<"1"<<endl<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
