//GZ-J00365 ºî¶÷Í® 
#include<bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
};
node c;
node s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c.a>>c.b;
	cin>>s.a>>s.b;
	if(c.a==s.a){
		cout<<1;
		if(c.b[0]==s.b[0]&&c.b[1]==s.b[1]){
			cout<<1;
			if((c.b[2]=='C'||c.b[2]=='D')&&(s.b[2]=='C'||s.b[2]=='D')){
				cout<<"00";
			}
			else if(abs(c.b[2]-s.b[2])<=2){
				cout<<1;
				if(abs(c.b[2]-s.b[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else {
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
