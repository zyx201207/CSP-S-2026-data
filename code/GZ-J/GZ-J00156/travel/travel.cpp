//GZ-J00156 遵义市播州区实验学校 余晟睿
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	char q,e;
	int r,x;
	cin>>a>>b>>c>>d;
	
	q=b[2];
	e=d[2];
		r=b[1];
		x=d[1];
	cout<<r<<" "<<x<<" "<<q<<" "<<e;
	if(a==c){
		 cout<<"1";
		 if(r==x){
			 cout<<"1";	
			 if(q=='A'||q=='B'||q=='c'){
			 	if(e=='A'||e=='B'||e=='c'){
			 		cout<<"1";
			 		if(q=='A'&&e=='B'||q=='B'&&e=='A'||q=='C'&&e=='B'||q=='B'&&e=='C'){
			 			cout<<'1';
					 }
					 else  cout<<"0";
				 }
				 else  cout<<"00";
			 }
			 else if(q=='D'||q=='F'){
			 	if(e=='D'||e=='F'){
			 		cout<<"1";
			 		if(q=='D'&&e=='F'||q=='F'&&e=='D'){
			 			cout<<"1";
					 }
					 else  cout<<"0";
				 }
				 else cout<<"00";
			 }
		} 
	else cout<<"000";
	} 
	else cout<<"0000";
		
	
	fclose(stdin);
	fclose(stdout);
}
