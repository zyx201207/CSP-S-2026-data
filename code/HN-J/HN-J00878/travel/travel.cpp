#include<bits/stdc++.h>
using namespace std;
struct t{
	string a;
	string b;
};
t num1,num2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>num1.a>>num1.b;
	cin>>num2.a>>num2.b;
	if(num1.a==num2.a){
		cout<<1;
		if(num1.b[0]==num2.b[0]&&num1.b[1]==num2.b[1]){
			cout<<1;
			if(num1.b[2]"A"&&num1.b[2]<="C"&&num2.b[2]>="A"&&num2.b[2]<="C"||num1.b[2]>="D"&&num1.b[2]<="F"&&num2.b[2]>="D"&&num2.b[2]<="F"){
				cout<<1;
				if(int(num1.b[2])-1==int(num2.b[2])||int(num1.b[2])+1==int(num2.b[2])){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
} 
