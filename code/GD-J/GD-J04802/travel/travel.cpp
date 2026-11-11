#include <bits/stdc++.h>
using namespace std;
//const int uid=927587;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		cout<<1;
		if (s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			int side1=0,side2=0;
			for (int i='A';i<='C';i++){
				if (s1[2]==i) side1=1;
			}
			if (!side1) side1=2;
			for (int i='A';i<='C';i++){
				if (s2[2]==i) side2=1;
			}
			if (!side2) side2=2;
			if (side1==side2){
				cout<<"1";
				if (abs(s2[2]-s1[2])==1){
					cout<<"1";
				}else cout<<"0";
			}else{
				cout<<"00";
			}
		}
		else cout<<"000";
	}else{
		cout<<"0000";
	}
}
