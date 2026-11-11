#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d,i=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		i+=1000;
		if(-5<'b'-'d'&&'b'-'d'<5){
			i+=100;
			if(-3<'b'-'d'&&'b'-'d'<-1){
				cout<<"1110";
				}
				else if(1<'b'-'d'&&'b'-'d'<3){
					cout<<"1110";
					}
			else if(-2<'b'-'d'&&'b'-'d'<0){
				cout<<"1111";
				}
			else if(0<'b'-'d'&&'b'-'d'<2){
				cout<<"1111";
				}
			
			
		}
		else {
			cout<<"1100";
			}
		}
	else  {
		cout<<"0000";
	}
	
	
	
	return 0;
}


