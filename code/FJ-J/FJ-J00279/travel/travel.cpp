#include<bits/stdc++.h>
using namespace std;
int n1,n2;
bool b1,b2,b3,b4;
string s1,s2;
bool check_p(){
	string num1="",num2="";
	num1+=s1[0]+s1[1];
	num2+=s2[0]+s2[1];
	return num1==num2;
}
bool check_c(){
	char c1=s1[2],c2=s2[2];
	if(c1=='A'||c1=='B'||c1=='C')return c2=='A'||c2=='B'||c2=='C';
	else return c2=='D'||c2=='F';
}
bool check_l(){
	char c1=s1[2],c2=s2[2];
	if(c1=='D'||c1=='F'){
		return 1;
	}else{
		if((c1=='A'&&c2=='B')||(c1=='B'&&c2=='C')||(c1=='B'&&c2=='A')||(c1=='C'&&c2=='B'))return 1;
		else return 0;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	if(n1==n2){
		b1=1;
		b2=check_p();
		if(b2){
			b3=check_c();
			if(b3){
				b4=check_l();
			}
		}
	}
	cout<<b1<<b2<<b3<<b4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

