#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string num1,num2;
char abc1,abc2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	for(int i=0 ; i<s1.size() ; i++){
		if(i==2){
			abc1=s1[i];
			abc2=s2[i];
		}else{
			num1+=s1[i];
			num2+=s2[i];
		}
	}
	if(c1==c2){
		cout <<1;
		if(num1==num2){
			cout <<1;
			if((abc1=='D' && abc2!='F') || (abc2!='D' && abc1=='F')){
				cout <<00;
			}else{
				cout <<1;
				if(abs((int)abc1-(int)abc2)==1){
					cout <<1;
				}else{
					cout <<0;
				}
			}
		}else{
			cout <<000;
		}
	}else{
		cout <<0000;
	}
	return 0;
} 
