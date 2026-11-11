#include<iostream>
using namespace std;
string c1,s1,c2,s2;
int car1,car2,rw1,rw2;
char st1,st2;
bool check(char a,char b){
	if(a=='A')return b=='B';
	else if(a=='B')return (b=='A')||(b=='C');
	else if(a=='C')return b=='B';
	else if(a=='D')return b=='F';
	else return b=='D';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	car1=(c1[0]-'0')*10+(c1[1]-'0');
	car2=(c2[0]-'0')*10+(c2[1]-'0');
	rw1=(s1[0]-'0')*10+(s1[1]-'0');
	rw2=(s2[0]-'0')*10+(s2[1]-'0');
	st1=s1[2];st2=s2[2];
	if(car1==car2){
		cout<<"1";
		if(rw1==rw2){
			cout<<"1";
			if((('A'<=st1&&st1<='C')&&('A'<=st2&&st2<='C'))
			   ||(('D'<=st1&&st1<='F')&&('D'<=st2&&st2<='F'))){
			   	cout<<"1";
			   	if(check(st1,st2))cout<<"1";
			   	else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else{
		cout<<"0000";
	}
} 
