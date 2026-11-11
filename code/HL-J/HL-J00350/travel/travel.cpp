#include <iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int a=0,b=0,c=0,d=0;
	cin>>c1>>s1>>c2>>s2;
	int i1,i2;
	i1=(s1[0]-'0')*10+(s1[1]-'0');
	i2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		a=1;
		if(i1==i2){
			b=1;
			if(s1[2]<='C'&&s2[2]<='C'){
				c=1;
				if(s1[2]=='A'&&s2[2]=='B'){
					d=1;
				}
				else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
					d=1;
				}
				else if(s1[2]=='C'&&s2[2]=='B'){
					d=1;
				}
			}
			else if(s1[2]>='D'&&s2[2]>='D'){
				c=1;
				if(s1[2]=='D'&&s2[2]=='F'){
					d=1;
				}
				else if(s1[2]=='F'&&s2[2]=='D'){
					d=1;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
