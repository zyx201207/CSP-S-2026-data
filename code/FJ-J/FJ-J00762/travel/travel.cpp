#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int temp1,temp2;
		temp1=(s1[0]-'0')*10+(s1[1]-'0');
		temp2=(s2[0]-'0')*10+(s2[1]-'0');
		if(temp1==temp2){
			cout<<"1";
			char t1,t2;
			t1=s1[2];
			t2=s2[2];
			if((t1<='C'&&t2<='C')||(t1>='D'&&t2>='D')){
				cout<<"1";
				if((t1=='A'&&t2=='C')||(t1=='C'&&t2=='A')){
					cout<<"0";
				}
				else{
					cout<<"1";
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
