#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2[3],s1,s2[3];
	int a,b,c,d;
	cin>>c1>>c2[3]>>s1>>s2[3];
	if(c1==s1){
		a=1;
		if(c2[0]==s2[0] && c2[1]==s2[1]){
			b=1;
			if(c2[2]='A' && s2[2]='B'||(c2[2]='A' && s2[2]='C')||(c2[2]='B' && s2[2]='C')||(c2[2]='D' && s2[2]='F')||(s2[2]='A' && c2[2]='B')||(s2[2]='A' && c2[2]='C')||(s2[2]='B' && c2[2]='C')||(s2[2]='D' && c2[2]='F')){
				c=1;
				if((c2[2]='A' && s2[2]='B')||(c2[2]='B' && s2[2]='C')||(c2[2]='D' && s2[2]='F')||(s2[2]='A' && c2[2]='B')||(s2[2]='B' && c2[2]='C')||(s2[2]='D' && c2[2]='F')){
					d=1;
					cout<<a<<b<<c<<d;
					return 0;
			}else{
				c=0;
				d=0;
				cout<<a<<b<<c<<d;
				return 0;
			}	
		}else{
			b=0;
			c=0;
			d=0;
			cout<<a<<b<<c<<d;
			return 0;
		}
	}else{
		a=0;
		b=0;
		c=0;
		d=0;
		cout<<a<<b<<c<<d;
		return 0;
	}
	}
	return 0;
}
//kskbl wkzdjd;
