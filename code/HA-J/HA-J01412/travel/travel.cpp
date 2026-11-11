#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
string a,b,c,d,x;
    cin>>a>>b>>c>>d;
    if(a[0]==c[0] and a[1]==c[1]){
    	x[0]='1';
    	if(b[0]==d[0] and b[1]==d[1]){
    	    x[1]='1';
    	    if((b[2]<='C' and d[2]<='C')||(b[2]>='D' and d[2]>='D')){
    	    	x[2]='1';
    	    	if(abs(b[2]-d[2])==1){
    	    		x[3]='1';
		    	}else{
		    		x[3]='0';
		    	}
		    }else{
		    	x[2]='0';
		    	x[3]='0';
		    }
	    }else{
	    	x[1]='0';
	    	x[2]='0';
	    	x[3]='0';
	    }
	}else{
		x[0]='0';
		x[1]='0';
		x[2]='0';
		x[3]='0';
	}
	
	cout<<x[0]<<x[1]<<x[2]<<x[3];
	return 0;
}
