#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b;
	cin>>a>>b;
	while(b--){
		int c,d;
		cin>>c>>d;
		for(int i=1;i<=c;i++)cin>>d;
		cout<<c-5<<endl;
	}
	return 0;
}
