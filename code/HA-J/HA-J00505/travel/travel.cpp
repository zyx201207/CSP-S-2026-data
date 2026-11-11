#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int a1=s1[0]*10+s1[1],a2=s2[0]*10+s2[1];
		if(a1==a2){
			cout<<1;
			int num1=s1[2]-'A',num2=s2[2]-'A';
			if((0<=num1&&num1<=2&&0<=num2&&num2<=2)||(3<=num1&&3<=num2)){
				cout<<1;
				if((abs(num1-num2)==1&&((s1[2]!='C'&&s2[2]!='D')||(s1[2]!='C'&&s2[2]!='D')))||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
					cout<<1;
				}else{
					cout<<0;
				}
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
