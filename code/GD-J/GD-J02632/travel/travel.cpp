#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int sp1,sd1,sp2,sd2;
		sp1=(s1[0]-'0')*10+s1[1]-'0';
		sp2=(s2[0]-'0')*10+s2[1]-'0';
		sd1=s1[2]-'A';
		sd2=s2[2]-'A';
		if(sp1==sp2){
			cout<<"1";
			if((sd1<=2&&sd2<=2)||(sd1>2&&sd2>2)){
				cout<<"1";
				if(abs(sd1-sd2)<=1){
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
	else cout<<"0000";
	
	return 0;
}
