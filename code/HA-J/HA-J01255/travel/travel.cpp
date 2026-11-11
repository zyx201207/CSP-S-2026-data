#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1])
	    cout<<1;
	else
	    cout<<0;
	if(a[0]==c[0]&&a[1]==c[1]){
		if(b[0]==d[0]&&b[1]==d[1])
	        cout<<1;
	}
	    
	else
	    cout<<0;
	if(a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]){
		if(b[2]!='C'&&d[2]!='D'&&b[2]!='D'&&d[2]!='C'){
			if(b[2]+2==d[2]||d[2]+2==b[2]||b[2]+1==d[2]||d[2]+1==b[2])
			    cout<<1;
		}
		    
	}    
	else
	    cout<<0; 
	if(a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]){
		if(b[2]!='C'&&d[2]!='D'&&b[2]!='D'&&d[2]!='C'){
			if(b[2]+1==d[2]||d[2]+1==b[2])
		        cout<<1; 
	    } 
	}    
	else
	    cout<<0; 	   
	return 0;
}
