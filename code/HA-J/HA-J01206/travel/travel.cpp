#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		int shu1=(s1[0]-'0')*10+s1[1]-'0',shu2=(s2[0]-'0')*10+s2[1]-'0';
		if(shu1!=shu2){
			cout<<"000"<<endl;
			return 0;
		}
		else{
			cout<<1;
			char zimu1=s1[2],zimu2=s2[2];
			if(!(zimu1=='A' && zimu2=='B' ||zimu1=='B' && zimu2=='A' ||zimu1=='A' && zimu2=='C' ||zimu1=='C' && zimu2=='A' ||zimu1=='C' && zimu2=='B' ||zimu1=='B' && zimu2=='C' ||zimu1=='D' && zimu2=='F' ||zimu1=='F' && zimu2=='D')){
				cout<<"00";
				return 0;
			}
			else{
				cout<<1;
				if(!(zimu1=='A' && zimu2=='B' ||zimu1=='B' && zimu2=='A' ||zimu1=='C' && zimu2=='B' ||zimu1=='B' && zimu2=='C' ||zimu1=='D' && zimu2=='F' ||zimu1=='F' && zimu2=='D')){
					cout<<0;
					return 0;
				}
				else{
					cout<<1;
				}
			}
		}
	}
	return 0;
}
