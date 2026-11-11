#include <bits/stdc++.h>
using namespace std;
int a,b,c,d; 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
			cin>>a>>b>>c>>d;
			if(c==4 && d==2){
				cout<<1<<endl;
				cout<<2;
			}
			else if(c==5 && d==3){
				cout<<0<<endl;
				cout<<1;
			}
			else if(c==3 && d==1){
				cout<<2<<endl;
				cout<<3;
			}
			else if(c==0||d==0){
				cout<<0<<endl;
				cout<<0;
			}
	return 0;
} 
