#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("trauel.in",'r',stdin)
freopen("trauel.out",'w',stdout)
    int b1,b2,a1,a2,a3,a4;	
	string c1,c2;
	char s1,s2;
	cin>>c1>>b1>>s1>>c2>>b2>>s2;
	if(c1==c2){
		a1=1;
		cout<<a1;
    }else{
    	a1=0;
    	cout<<a1;
    }
    if(a1==0){
    	a2=0;
    	cout<<0;
	}else{
		if(b1==b2){
		   a2=1;
		   cout<<a2;	
		}else{
		   a2=0;
		   cout<<a2;	
		}
    }
	if(((s1=='F'||s1=='D')&&(s2=='A'||s2=='B'||s2=='C'))||((s1=='A'||s1=='B'||s1=='C')&&(s2=='F'||s2=='D'))){
		a3=0;
			cout<<a3;
		}else{
			if(a2==0){
				a3=0;
			cout<<a3;	
			}else{
				a3=1;
				cout<<a3;
			}
        }
    if(a3==0){
    	a4=0;
    	cout<<a4;
    }else{
        if((s1=='A'&&s2=='B')||(s1=='B'&&s2=='C')||(s1=='D'&&s2=='F')||(s2=='A'&&s1=='B')||(s2=='B'&&s1=='C')||(s2=='D'&&s1=='F')){
        a4=1;
		cout<<a4;	
        }else{
        	a4=0;
        	cout<<a4;
        }
    }
}
