#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int t1,t2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			t1=s1[2]-'A';
			t2=s2[2]-'A';
			if((0<=t1&&t1<=2&&0<=t2&&t2<=2)||(3<=t1&&t1<=5&&3<=t2&&t2<=5)){
				if(abs(t1-t2)==1||(t1==3&&t2==5)||(t1==5&&t2==3)){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			} 
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
