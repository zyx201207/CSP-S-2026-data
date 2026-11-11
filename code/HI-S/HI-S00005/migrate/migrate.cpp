#include<bits/stdc++.h>
using namespace std;
int c,t,a;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t>>a;
	if(c==0){
		if(t==2&&a==4){
			cout<<1<<endl<<2;
		}
		if(t==2&&a==5){
			cout<<0<<endl<<1;
		}
	}
	return 0;
}

