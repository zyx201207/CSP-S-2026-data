#include<bits/stdc++.h>
using namespace std;
int n1,n2;
string s1,s2;
bool a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	if(n1!=n2){
		cout<<"0000";
		return 0;
	}
	int num1,num2;
	for(int i=0;i<s1.size()-1;i++){
		num1*=10;
		num2*=10;
		num1+=int(s1[i]-'0');
		num2+=int(s2[i]-'0');
	}
	if(num1!=num2){
		cout<<1000;
		return 0;
	}
	num1=int(s1[s1.size()-1]-'A');
	num2=int(s2[s2.size()-1]-'A');
	if(num1<=2){
		a=1;
	}
	if(num2<=2){
		b=1;
	}
	if(a!=b){
		cout<<1100;
		return 0;
	}
	if(abs(num1-num2)!=1){
		cout<<1110;
		return 0;
	}
	cout<<1111;
	return 0;
} 
