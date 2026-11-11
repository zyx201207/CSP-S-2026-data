#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,sk1,sk2; 
bool a,b,c,d;
map<char,int>m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	sk1 = s1[0];
	sk1+=s1[1];
	sk2 = s2[0];
	sk2+=s2[1];
	char op1 = s1[2], op2=s2[2];
	m['A']=1,m['B']=1,m['C']=1,m['D']=2,m['F']=2; 
	if(c1==c2){
		a=1;
		if(sk1 == sk2){
			b=1;
			if(m[op1]==m[op2]){
				c=1;
				if((abs(int(op1)-int(op2))==1)||(op1=='D'&&op2=='F')){
					d=1;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}

