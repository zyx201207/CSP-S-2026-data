#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,x1,c2,s2,x2,s11,s12,s21,s22;
	int a=0,b=0,c=0,d=0;
	cin>>c1>>s1>>c2>>s2;
	s11=s1[0];
	s12=s1[1];
	s21=s2[0];
	s22=s2[1];
	x1=s1[2];
	x2=s2[2];
	if(c1==c2){
		a=1;
		if(s11==s21 && s12==s22){
			b=1;
			if(((x1[0]=='A'||x1[0]=='B'||x1[0]=='C')&&(x2[0]=='A'||x2[0]=='B'||x2[0]=='C'))||((x1[0]=='D'||x1[0]=='E')&&(x2[0]=='D'||x2[0]=='E'))){
				c=1;
				if((x1[0]=='A'||x2[0]=='C')&&(x1[0]=='C'||x2[0]=='A')){
					d=0;
				}else{ 
					d=1;
				}
			}
		}
	}
	if(a==0){
		a=b=c=d=0;
	}
	if(a==1&&b==0){
		b=c=d=0;
	}
	if(a==b==1&&c==0){
		c=d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
