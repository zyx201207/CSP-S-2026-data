#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num=0,num1=0,num2=0,num3=0;
int main(int argc, char** argv) {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//
	int c2,c1;
	string s2,s1;
	cin>>c1>>s1>>c2>>s2;
	
	
	if(c1==c2){
		num+=1;
	}
	
	
	int a1=(int)(s1[0]+s1[1]),a2=(int)(s2[0]+s2[1]);
	if(a1==a2){
		num1+=1;
	}
	
	
	int b1=(int)s1[2],b2=(int)s2[2];
	if(b1<=67 && b2<=67){
		num2+=1;
	}else if(b1<=69 && b2<=69 && num2==0){
		num2+=1;
	}
	
	
	if(num==1 && num1==1 && num2==1 && ((b1+1)==b2 || (b2+1)==b1)){
		num3+=1;
	}
	
	
	cout<<num<<num1<<num2<<num3<<endl;
	return 0;
}
