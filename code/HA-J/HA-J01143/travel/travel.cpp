#include<bits/stdc++.h>
using namespace std;
string cx,sx,cr,sr;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	//È«»»p£¬fÊäÈëÊä³ö 
	cin>>cx>>sx>>cr>>sr;
	if(cx==cr){
		cout<<1;
			if(sx[0]==sr[0] && sx[1]==sr[1]){
			cout<<1;
			int b1=sx[2]-64,b2=sr[2]-64;
			if(b1+b2<=5){
				cout<<1;
				if(b1-b2==1 or b1-b2==-1)cout<<1;
				else cout<<0;
			}else if(b1+b2==10){
				cout<<1<<1;
			}else{
				cout<<0<<0;
			}
		}  
		else cout<<0<<0<<0;
	}	
	else cout<<0<<0<<0<<0;
	
	fclose(stdin);fclose(stdout);
	return 0;
}
