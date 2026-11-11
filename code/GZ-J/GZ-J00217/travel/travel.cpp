//GZ-J00217,金沙第一中学，姓名:王俊泽 
#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=s1[2];
	b=s2[2];
	if(c1==c2){
		cout<<1;
			if(s1[0]==s2[0]){
		        if(s1[1]==s2[1]){
			        cout<<1;
			        if(a=='A'||a=='B'||a=='C'){
		                if(b=='A'||b=='B'||b=='C')cout<<1;
			            else{
			                cout<<0;
		                }
	                }else if(a=='D'||a=='F'){
		                if(b=='D'||b=='F')cout<<1;
		                else{
		                	cout<<0;
					    }  
	                }
		        }else{
			        cout<<0<<0;
		        }
	        }else{
		        cout<<0<<0;
	        }
	}else{
		cout<<0<<0<<0;
	}
	if(a+1==b||b+1==a){
		if(a=='C'&&b=='D'||a=='D'&&b=='C')cout<<0;
		else{
			cout<<1;
		}
	}else{
		cout<<0;
	}
	return 0;
}
