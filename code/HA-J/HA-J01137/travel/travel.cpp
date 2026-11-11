#include<bits/stdc++.h>
using namespace std;
int main(){
	//((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char a=c1[1];
	char b=s1[1];
	char c=c2[1];
	char d=s2[1];
	//cout<<a<<b<<c<<d;
	if(a==c){
		cout<<'1';
		if(b==d){
			cout<<'1';
			if((s1[2]<='C'&&s1[2]>='A')&&(s2[2]<='C'&&s2[2]>='A')){
				if((int)s1[2]-s2[2]==1||(int)s1[2]-s2[2]==-1){
					cout<<"11";
				}else{
					cout<<"10";
				}
			}else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
				cout<<"11";
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
