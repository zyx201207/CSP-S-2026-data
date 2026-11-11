#include<bits/stdc++.h>
using namespace std;
int a,b,e,f;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	e=c[2]-'A'+1;
	f=d[2]-'A'+1;
	if(a!=b){
		cout<<"0000";
	}
	else{
		cout<<"1";
		if(c[0]==d[0]&&c[1]==d[1]){
			cout<<"1";
			if(1<=e&&e<=3&&1<=f&&f<=3){
				cout<<"1";
				if(e-f==1||f-e==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(4<=e&&e<=6&&4<=f&&f<=6){
				cout<<"1";
				if(e-f==1||f-e==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	return 0;
}