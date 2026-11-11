#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
bool b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	b[(int)(s1[2]-'A')]=1;
	b[(int)(s2[2]-'A')]=1;
	if(c1==c2){
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<'1';
			if((b[0]&&b[1])||(b[1]&&b[2])||(b[0]&&b[2])||(b[3]&&b[5])){
				cout<<'1';
				if((b[0]&&b[1])||(b[1]&&b[2])||(b[3]&&b[5])){
					cout<<'1';
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
	else{
		cout<<"0000";
	}
	return 0;
}
