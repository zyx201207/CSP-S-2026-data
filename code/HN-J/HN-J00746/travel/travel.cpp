#include<bits/stdc++.h>
using namespace std;
int a1,b1,a3,b3;
string a2,b2,a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin >>a1>>a2>>b1>>b2;
	a3=a2[2]-'0';
	b3=b2[2]-'0';
	a=a2[0]+a2[1];
	b=b2[0]+b2[1]; 
	if(a1==b1){
		cout <<"1";
	}else{
		cout <<"0";
	}
	if(a1==b1&&a==b){
		cout <<"1";
	}else{
		cout <<"0";
	}
	if(a1==b1&&a==b){
		if(a3>=17&&a3<=19){
			if(b3>=17&&b3<=19){
			    cout <<"1"; 
			}else{
				cout <<"0";
	    	}
		}else{
			if(b3>=20&&b3>=21){
				cout <<"1";
			}else{
				cout <<"0";
			}
		}
	}else{
		cout <<"0";
	}
	if(a1==b1&&a==b){
		if(a3==19){
		    if(b3==a3-1){
			    cout <<"1";
		    }else{
			    cout <<"0";
		    }
	    }
	    if(a3==20){
		    if(b3==a3+1){
			    cout <<"1";
		    }else{
			    cout <<"0";
		    }
     	}
	    if(a3!=19&&a3!=20){
		    if(b3==a3-1||b3==a3+1){
		        cout <<"1";
	        }else{
		        cout <<"0";
         	}
	    }
	}else{
		cout <<"0";
	}
	
	
	return 0;
}
