#include<iostream>
using namespace std;
char c1[3],s1[4],c2[3],s2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++)cin>>c1[i];
	for(int i=1;i<=3;i++)cin>>s1[i];
	for(int i=1;i<=2;i++)cin>>c2[i];
	for(int i=1;i<=3;i++)cin>>s2[i];
	for(int i=1;i<=2;i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
	}
	for(int i=1;i<=2;i++){
		if(s1[i]!=s2[i]){
			cout<<"1000";
			return 0;
		}
	}
	if(s1[3]=='A'&&s2[3]=='D'||s1[3]=='A'&&s2[3]=='F'||s1[3]=='B'&&s2[3]=='D'||s1[3]=='B'&&s2[3]=='F'||s1[3]=='C'&&s2[3]=='D'||s1[3]=='C'&&s2[3]=='F'||s1[3]=='D'&&s2[3]=='A'||s1[3]=='D'&&s2[3]=='B'||s1[3]=='D'&&s2[3]=='C'||s1[3]=='E'&&s2[3]=='A'||s1[3]=='E'&&s2[3]=='B'||s1[3]=='E'&&s2[3]=='C'){
		cout<<"1100";
		return 0;
	}
	if(s1[3]=='A'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='A'||s1[3]=='B'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='B'||s1[3]=='E'&&s2[3]=='D'||s1[3]=='D'&&s2[3]=='E'){
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0;
}
