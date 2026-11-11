#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<"1";
		string x1="",x2="";
		x1 = s1[0] + s1[1];
		x2 = s2[0] + s2[1];
		if(x1 == x2){
			cout<<"1";
			char x3 = s1[2],x4 = s2[2];
			if(((x3 == 'F' || x3 == 'D') && (x4 == 'D' || x4 == 'F')) || ((x3 == 'A' || x3 == 'B' || x3 == 'C') && (x4 == 'A' || x4 == 'B' || x4 == 'C'))){
				cout<<"1";
				if(((x3 == 'F' || x3 == 'D') && (x4 == 'D' || x4 == 'F')) || (x3 == 'A' && x4 == 'B')
				|| (x3 == 'B' && x4 == 'A') || (x3 == 'B' && x4 == 'C') || (x3 == 'C' && x4 == 'B')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
