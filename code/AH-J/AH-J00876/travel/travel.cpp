#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a[0]==c[0]&&a[1]==c[1])cout<<'1';
    else{
		cout<<'0';
        f=0;
    }
    if(b[0]==d[0]&&b[1]==d[1]&&f==1){
		cout<<'1';
    }else{
		cout<<'0';
		f=0;
    }
    if(f==1){
	   if(d[2]>'C'&&b[2]>'C'){
	       cout<<'1';
	   }else if(d[2]<'D'&&b[2]<'D'){
		   cout<<'1';
	   }
	   else{
		   cout<<'0';  
		   f=0;
	   }	
	}else cout<<'0';
	if(f==1){
	    if(abs(d[2]-b[2])==1)cout<<'1';
	    else cout<<'0';
	}else cout<<'0';
    return 0;
}
