#include <bits/stdc++.h>
using namespace std;
int a,c,e,f;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	f=b[2];
	e=d[2];
	if(a==c){
		cout<<1;
		if(b[0]==d[0] and b[1]==d[1]){
		cout<<1;
			if((e>=68 and f>=68)  or e<68 and f<68){
				cout<<1;
				if(e==1+f or e==f-1 ){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<00;
			}
		}
		else{
			cout<<000;
		}
	}
	else{
		cout<<0000;
	}
	return 0;
}
