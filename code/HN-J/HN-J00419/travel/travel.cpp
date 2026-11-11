#include<bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2,z1,z2;
string s1,s2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1=(( s1[0]-'0')*10+s1[1]-'0');
	p2=(( s2[0]-'0')*10+s2[1]-'0');
	z1=s1[2]-'A',z2=s2[2]-'A';

	if(c1!=c2) 
		cout<<"0000\n";
	else if(p1!=p2)
		cout<<"1000\n";
	else
		if(0<=z1 && z1<=2 && 0<=z2 && z2<=2)
			if(abs(z2-z1)==1) cout<<"1111\n";
			else cout<<"1110\n";
			
		else if(3<=z1 && z1<=4 && 3<=z2 && z2<=4)
			if(abs(z2-z1)==1) cout<<"1111\n";
			else cout<<"1110\n";
			
		else cout<<"1100\n";
		
		
	
	return 0;
}
