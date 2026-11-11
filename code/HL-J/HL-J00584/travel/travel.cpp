#include<bits/stdc++.h>
using namespace std;
string s,st,str,stri;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool a=false,b=false,c=false,d=false;
    cin>>s>>st>>str>>stri;
    for(int i=0;i<2;i++){
        if(s[i]==str[i]){
            a=true;
        }
        else{
            a=false;
            break;
        }
    }
    if(a==1){
    	cout<<1;
	}
	else{
		cout<<0;
		return 0;
	}
	for(int i=0;i<2;i++){
		if(st[i]==stri[i]&&a==1){
            b=true;
        }
        else{
            b=false;
            break;
        }
	}
	if(b==1){
		cout<<1;
	} 
	else{
		cout<<0;
	}
	for(int i=0;i<2;i++){
		if(st[i]==stri[i]&&a==1){
            c=true;
        }
        else{
            c=false;
            break;
        }
	}
	if(c==1){
		if(st[2]=='A'||st[2]=='B'||st[2]=='C'){
			if(stri[2]=='A'||stri[2]=='B'||stri[2]=='C'){
				c=true;
			}
			else{
				c=false;
			}
		}
		else{
			if(stri[2]=='D'||stri[2]=='E'){
				c=true;
			}
			else{
				c=false;
			}
		}
	}
	if(c==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	for(int i=0;i<2;i++){
        if(st[i]==stri[i]&&a==true){
            d=true;
        }
        else{
            c=false;
            break;
        }
    }
    if(d==true){
        if(st[2]=='A'&&stri[2]=='B'){
            d=true;
        }
        else{
            d=false;
        }
    }
    if(d==true){
        if(st[2]=='B'&&stri[2]=='C'){
            d=true;
        }
        else{
            d=false;
        }
    }
    if(d==true){
        if(st[2]=='D'&&stri[2]=='E'){
            d=true;
        }
        else{
            d=false;
        }
    }
    if(d==true){
    	cout<<1;
	}
	else{
		cout<<0;
	}
    return 0;
}
 
