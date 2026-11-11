#include <bits/stdc++.h>
using namespace std;
string n,m,x,y;
int a,b,c,d;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>x>>y;
	a=m[2]-0;
	b=y[2]-0;
	c=a+b;
	
	if(a>b){
		d=a-b;
	}else{
		d=b-a;
	}
	if(n==x){
		cout<<"1";
		
		if(m[0]==y[0] && m[1]==y[1]){
			cout<<"1";
			
			if(((a==65 || a==66 || a==67 )&& (b==65||b==66 || b==67)) || ((a==68 || a==70 )&& (b==68 || b==70))){
				cout<<"1";
				
				if(d==1){
					cout<<"1";		
				}else{
					cout<<"0";
				}//4
				
			}else{
				cout<<"00";
			}//3
			
		} 
		else{
			cout<<"000";
		}//2
		
	}else{
		cout<<"0000";
	}//µÚ1¸ö
		
	
	
	return 0;
}
