  #include<bits/stdc++.h>
 using namespace std;
 int main(){
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	string a1,a2,b1,b2;
 	char a3,a4,a5,b3,b4,b5;
 	a2=a3+a4+a5;
 	b2=b3+b4+b5;
	 int a,b,c,d;
 	
 	cin>>a1>>a2>>b1>>b2;
 	
 	
 	if(a1==b1)a=1;
 	else if(a1!=b1){
 		cout<<"0000";
 		return 0;
	 }
 	if(a3+a4==b3+b4 )b=1;
 	else if(a3+a4!=b3+b4){
 		cout<<"1000";
 		return 0;
 		
	 }
	 if((a5=='A'&&b5=='B')||(a5=='A'&&b5=='C')||(a5=='B'&&b5=='C')||(a5=='B'&&b5=='A')||(a5=='C'&&b5=='A')||(a5=='C'&&b5=='B') )
	 c=1;
	 else{
	 	cout<<"1100";
	 	return 0;
	 	
	 }
	 

 	
 	if(a5=='A'&&b5=='B')d=1;
 	else if(a5=='B'&&b5=='C')d=1;
 	else if(a5=='B'&&b5=='A')d=1;
	else if(a5=='C'&&b5=='B')d=1;
	else if(a5=='D'&&b5=='F')d=1;
	else if(a5=='F'&&b5=='D')d=1;
	else d=0;
	cout<<"111"<<d;

	
 	
 	
 	return 0;
 } 
