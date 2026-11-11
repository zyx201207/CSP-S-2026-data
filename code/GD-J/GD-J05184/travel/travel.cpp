#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1== c2){
		cout<<"1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout<<"1";
			char x1 = s1[2],x2 = s2[2];
			if(x1 >= 'D' && x2 >= 'D'){
				cout<<"11";
			}
			else if(x1 <= 'C' && x2 <= 'C'){
				cout<<"1";
				if(x1 == 'B' || x2 == 'B'){
					cout<<"1";
				}
				else cout<<"0";
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
}
