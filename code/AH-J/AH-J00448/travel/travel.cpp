#include<bits/stdc++.h>
using namespace std;
struct b{
string c,s;
}a,d;
bool f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a.c>>a.s>>d.c>>d.s;
    if(a.c[0]==d.c[0]&&a.c[1]==d.c[1]){
    	cout<<1;
    }else{
    	cout<<0;
    	f=1;
    }
    if(!f&&a.s[0]==d.s[0]&&a.s[1]==d.s[1]){
    	cout<<1;
    }else{
    	cout<<0;
    	f=1;
    }
    if(!f){
    	if((a.s[2]=='A'||a.s[2]=='B'||a.s[2]=='C')&&(d.s[2]=='B'||d.s[2]=='C'||d.s[2]=='A')){
    		cout<<1;
    	}else if((a.s[2]=='F'||a.s[2]=='D')&&(d.s[2]=='F'||d.s[2]=='D')){
    		cout<<1;
    	}else{
    		cout<<0;
    		f=1;
    	}
    }else{
    	cout<<0;
    	f=1;
    }
    if(!f){
    	if(a.s[2]=='A'&&d.s[2]=='B'){
    		cout<<1;
    	}else if(a.s[2]=='B'&&d.s[2]=='A'||d.s[2]=='C'&&a.s[2]=='B'){
    		cout<<1;
    	}else if(a.s[2]=='C'&&d.s[2]=='B'){
    		cout<<1;
    	}else if(a.s[2]=='D'&&d.s[2]=='F'){
    		cout<<1;
    	}else if(a.s[2]=='F'&&d.s[2]=='D'){
    		cout<<1;
    	}else{
    		cout<<0;
    	}
    }else{
    	cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
