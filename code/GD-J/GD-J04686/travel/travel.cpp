#include<bits/stdc++.h>
using namespace std;
bool m1,m2,m3,m4;
string c1,s1,c2,s2;
string n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)m1=1;
	
	string a,b;
	a=s1[0]+s1[1];
	b=s2[0]+s2[1];
	if(a==b){
		m2=1;
	}
	
	n=s1[2]+s2[2];
	if(m1&&m2&&(n=="DF"||n=="FD")){
		m3=1;m4=1;
	}
	else if(m1&&m2&&(s1[2]<='C'&&s2[2]<='C')){
		m3=1;
	}
	if(m1&&m2&&m3&&(s1[2]-s2[2]==1||s1[2]-s2[2]==-1))
		m4=1;
	cout<<m1<<m2<<m3<<m4;
	return 0;
} 
