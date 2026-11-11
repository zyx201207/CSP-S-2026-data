#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		int a1=s1[0]-48;
		a1*=10;
		a1=a1+s1[1]-48;
		int a2=s2[0]-48;
		a2*=10;
		a2=a2+s2[1]-48;
		if(a1!=a2){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			char c1=s1[2];
			char c2=s2[2];
			if(c1>c2){
				char c=c1;
				c1=c2;
				c2=c;
			}
			if((c1>='A'&&c2<='C')||(c1=='D'&&c2=='E')){
				cout<<"1";
				if(c2-c1==1){
					cout<<"1";
				}
				else cout<<"0";
				return 0;
			}
			else cout<<"00";
		}
	}
	return 0;
} 
