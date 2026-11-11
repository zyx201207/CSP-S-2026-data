#include<bits/stdc++.h>
using namespace std;
string cc,ss,ccc,sss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cc>>ss>>ccc>>sss;
	if(cc==ccc){
		cout<<'1';
		if(ss[0]==sss[0]&&ss[1]==sss[1]){
			cout<<'1';
			if((ss[2]=='A'&&sss[2]=='B')||(ss[2]=='A'&&sss[2]=='C')||(ss[2]=='B'&&sss[2]=='C')||(ss[2]=='D'&&sss[2]=='F')||(ss[2]=='B'&&sss[2]=='A')||(ss[2]=='C'&&sss[2]=='A')||(ss[2]=='C'&&sss[2]=='B')||(ss[2]=='F'&&sss[2]=='D')){
				cout<<'1';
				if((ss[2]=='A'&&sss[2]=='B')||(ss[2]=='B'&&sss[2]=='C')||(ss[2]=='D'&&sss[2]=='F')){
					cout<<'1';
				}
				else{
					cout<<'0';
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
	else{
		cout<<"0000";
	}
	return 0;
}
