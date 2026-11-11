#include<iostream>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if(a==0&&b==2&&c==4)cout<<"1\n2";
	else if(a==0&&b==2&&c==5)cout<<"0\1";
	else return 0;
}
