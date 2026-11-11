#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int car1=(c1[0]-'0')*10+c1[1]-'0';
	int car2=(c2[0]-'0')*10+c2[1]-'0';
	int p1=(s1[0]-'0')*10+s1[1]-'0';
	int p2=(s2[0]-'0')*10+s2[1]-'0';
	int ce1=s1[2]-'A'+1;
	int ce2=s2[2]-'A'+1;
	if(car1==car2){
		cout<<"1";
		if(p1==p2){
			cout<<"1";
			if(max(ce1,ce2)<=3||min(ce1,ce2)>=4){
				cout<<"1";
				if(abs(ce1-ce2)==1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
