#include <bits/stdc++.h>
using namespace std;
int a[5];
bool flag1=true,flag2=true,flag3=true;
char w1,w2,w3,w4;
string num1,num2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","l",stdout);
	cin >>a[1]>>num1>>a[2]>>num2;
	if (a[1]==a[2]){
		cout <<"1";
	}
	else{
		cout <<"0";
		flag1=false;
	}
	if (flag1){
	    for (int i=0;i<2;i++){
		    if (num1[i]!=num2[i]){
		    	flag2=false;
		    	break;
	    	}
    	}
    	if (flag2) cout <<"1";
	    else cout <<"0";
    }
    else{
    	cout <<"0";
    	flag2=false;
	}
	if (flag2){
		if (num1[2]>='A'&&num1[2]<='C'){
			if (num2[2]>='A'&&num2[2]<='C') cout <<"1";
			else{
				cout <<"0";
				flag3=false;
			}
		}
		else{
			if (num2[2]>='D'&&num2[2]<='F') cout <<"1";
			else{
				cout <<"0";
				flag3=false;
			}
		}
	}
	else{
		cout <<"0";
		flag3=false;
	}
	if (flag1&&flag2&&flag3){
		w1=num1[2];
		w2=num2[2];
		w4=w1-1;
		w3=w1+1;
		if (w3==w2||w4==w2) cout <<"1";
		else cout <<"0";
	}
	else cout <<"0";
	return 0;
} 
