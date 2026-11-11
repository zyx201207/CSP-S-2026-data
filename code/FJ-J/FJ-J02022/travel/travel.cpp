#include<bits/stdc++.h>
using namespace std;
int a,b,ax,bx,ay,by;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
    char c;
    cin>>c;
    if(c=='0') cin>>c;
    a=c-'0';
    cin>>c;
    if(c=='0') cin>>c;
    ax=c-'0';
    cin>>c;
    ay=c-'0';
    ay-=16;
    
    cin>>c;
    if(c=='0') cin>>c;
    b=c-'0';
    cin>>c;
    if(c=='0') cin>>c;
    bx=c-'0';
    cin>>c;
    by=c-'0';
	by-=16;
	
    if(a==b){
    	cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(ax==bx) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(ay<4&&by<4||ay>=4&&by>=4) cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(abs(ay-by)==1) cout<<1;
	else cout<<0;
    return 0;
} 
