#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,a1="",b1="";
	char a,b;
	cin>>c1>>s1>>c2>>s2;
	a1+=s1[0];
	a1+=s1[1];
	a=s1[2];
	b1+=s2[0];
	b1+=s2[1];
	b=s2[2];
	
	if(c1==c2){
		cout<<1;
		if(a1==b1){
			cout<<1;
			if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='E'&&b>='D'&&b<='E')){
				cout<<1;
				if(a=='A'){
					if(b=='B'){
						cout<<1;
					}
					else{
						cout<<0;
						return 0;
					}
				}
				else if(a=='B'){
					if(b=='A'||b=='C'){
						cout<<1;
					}
					else{
						cout<<0;
						return 0;
					}
				}
				else if(a=='C'){
					if(b=='B'){
						cout<<1;
					}
					else{
						cout<<0;
						return 0;
					}
				}
				else if(a=='D'){
					if(b=='E'){
						cout<<1;
					}
					else{
						cout<<0;
						return 0;
					}
				}
				else if(a=='E'){
					if(b=='D'){
						cout<<1;
					}
					else{
						cout<<0;
						return 0;
					}
				}
			}
			else{
				cout<<0<<0;
				return 0;
			}
		}
		else{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
} 
