#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int pa1=(s1[0]-'0')*10+s1[1]-'0',pa2=(s2[0]-'0')*10+s2[1]-'0';
		if(pa1==pa2){
			cout<<"1";
			int zimu1=s1[2]-'A'+1,zimu2=s2[2]-'A'+1;
			if((zimu1<=3&&zimu2<=3)||(zimu1>=4&&zimu2>=4)){
				cout<<"1";
				if((zimu1>=4&&zimu2>=4)||(zimu1<=3&&zimu2<=3&&abs(zimu1-zimu2)==1)){
					cout<<"1";
				}
				else cout<<"0";
			}
			else{
				cout<<"00";
			}			
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
