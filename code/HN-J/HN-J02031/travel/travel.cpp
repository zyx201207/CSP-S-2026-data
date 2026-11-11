#include<bits/stdc++.h>
using namespace std;
int main(){
	/*freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);*/
	char a[10],b[10],c[10],d[10];
	cin>>a>>b>>c>>d;
    if(a[1]==c[1]&&a[0]==c[0]){
	  cout<<1;
	  if(b[1]==d[1]&&d[0]==b[0]){
	  	cout<<1;
	  	if(b[2]=='D'||b[2]=='F'){
	  		if(d[2]=='D'||d[2]=='F'){
	  			cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				cout<<1;
			}
			else cout<<0;
		}
	  }
	  else{
	  	cout<<0<<0;
	  }
	}
	else{
	  cout<<0<<0<<0<<0;
	  return 0;
	}
	
 if(a[1]==c[1]&&a[0]==c[0]){	
	 if(b[2]==d[2]&&abs(((b[0]-'0')*10+b[1]-'0')-((d[0]-'0')*10+d[1]-'0'))==1){
	  	cout<<1;
	  	return 0;
	   }
	   else{
	  	cout<<0;
	  	return 0;
	  }
	  
	  if(b[0]==d[0]&&b[1]==d[1]){
	  	if(b[2]=='F'&&d[2]=='D'||b[2]=='D'&&d[2]=='F'||b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'){
	  		cout<<1;
	  		return 0;
		  }
		  else{
		  	cout<<0;
		  	return 0;
		  }
	  }
	  
}
	return 0;
}
 
