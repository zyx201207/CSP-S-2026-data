#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	
	if(a==c){
		if(b[0]==d[0] and b[1]==d[1]){
			if((b[2]<='C') ^ (d[2]<='C')){
				
				cout<<"1100";
			}else{
				if((b[2]=='A' and d[2]=='C') or (b[2]=='C' and d[2]=='A')){
					cout<<"1110";
				}else{
					cout<<"1111";
				}
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
