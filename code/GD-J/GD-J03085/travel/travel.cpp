#include<bits/stdc++.h>
using namespace std;
string ch1,s1,ch2,s2;
int num1,num2,num3,num4;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>ch1>>s1>>ch2>>s2;
	c1=s1[2],c2=s2[2];
	num1=s1[0]-'0',num2=s1[1]-'0';//1 8
	num3=s2[0]-'0',num4=s2[1]-'0';//1 8
	
	if(ch1==ch2){
		cout <<1;
		if(num1==num3 && num2==num4){
			cout <<1;
			if((c1<='C' && c2<='C') || (c1>'C' && c2>'C')){
				cout <<1;
				int len=abs(int(c1-c2));
				if(c1<='C' && c2<='C' && len==1){
					cout <<1;
				}//×ó²à 
				else if(c1>'C' && c2>'C'){
					cout <<1;
				}
				else cout <<"0";
			}
			else {
				cout <<"00";
				return 0;
			}
		}
		else{
			cout <<"000";
			return 0;
		}
	} 
	else {
		cout <<"0000";
		return 0;//³µÏá
	}
	return 0;
} 
