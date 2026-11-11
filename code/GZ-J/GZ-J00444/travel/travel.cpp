//GZ-J00444 π®”Ó≥ø 
#include<bits/stdc++.h>
using namespace std;
struct zw{
	string c;
	string b;
}a[10];
int main(){
	freopen("trzvel.in","w",stdin);
	freopen("travel.out","w",stdout);
	string s,s1;
	for(int i=1;i<=2;i++)cin>>a[i].c>>a[i].b;
	s=a[1].b;
	s1=a[2].b;
	for(int i=1;i<=4;i++){
		if(a[1].c!=a[2].c){
			cout<<"0000";
			return 0;
		}
		else if(s[0]+s[1]==s1[0]+s1[1]){
			if((s[2]>='A'&&s[2]<='C'&&s1[2]>='A'&&s1[2]<='C')||(s[2]>='D'&&s[2]<='F'&&s1[2]>='D'&&s1[2]<='F')){
				if(int(s[2])-int(s1[2])==1||int(s[2])-int(s1[2])==-1){
					cout<<"1111";
					return 0;
				}
				else {
					cout<<"1110";
					return 0;
				}
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
		else {
			cout<<"1000";
			return 0;
		}
	}
	return 0;
}
