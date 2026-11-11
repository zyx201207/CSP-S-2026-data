#include<bits/stdc++.h>
using namespace std;
int c1,c2;
int pd1,pd2,pd3,pd4;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int num1=(s1[0]-'0')*10+(s1[1]-'0');
	int num2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		pd1=1;
		if(num1==num2){
			pd2=1;
			if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='E')&&(s2[2]>='D'&&s2[2]<='E'))){
				pd3=1; 
				if(abs(s1[2]-s2[2])==1){
					pd4=1;
				}
			}
			
		}
	}
	cout<<pd1<<pd2<<pd3<<pd4<<endl;
	return 0;
} 
