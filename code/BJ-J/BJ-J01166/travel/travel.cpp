#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
    cout<<1;
    }else{
		cout<<"0000";
		return 0;
	}
    bool flag=true;
    for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			flag=false;
			break;
		}
	}
	if(flag){
		cout<<1;
	}else{	
			cout<<"000";
			return 0;
	}
	bool flag1=false;
       if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		 if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
			 cout<<1;
			 flag1=true;
		 }
	   }else if(b[2]=='D'||b[2]=='E'){
		 if(d[2]=='D'||d[2]=='E'){
			 cout<<1;
			 flag1=true;
		 }
	   }
	   if(!flag1){
		   cout<<"00";
		   return 0;
	   }
  if(b[2]=='A'&&d[2]=='B'){
		 cout<<1;
		 return 0;
	 }else if(b[2]=='B'&&d[2]=='A'){
		 cout<<1;
		  return 0;
	 }
	 if(b[2]=='B'&&d[2]=='C'){
		 cout<<1;
		  return 0;
	 }else if(b[2]=='C'&&d[2]=='B'){
		 cout<<1;
		  return 0;
	 }
	 if(b[2]=='D'&&d[2]=='E'){
		 cout<<1;
	 }else if(b[2]=='E'&&d[2]=='D'){
		 cout<<1;
	 }else{
		 cout<<0;
	 }        
    return 0;
}
