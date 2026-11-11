#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1,s1,c2,s2;
	if(c1==c2)
		n[0]=1;
	else;
	
		n[0]=0;
	
	if(s1[0]=s2[0])
		if(s1[1]==s2[1])
			n[1]=1;
	else;
			n[1]=0;
		if(s1[2]='A')
			if(s1[2]='B')
				n[2]=1;
	else;
				n[2]=0;	

		if(s1[2]='A')
			if(s1[2]='C')
				n[2]=1;
	else;
				n[2]=0;	
		if(s1[2]='C')
			if(s1[2]='B')
				n[2]=1;
	else;
				n[2]=0;	
		if(s1[2]='D')
			if(s1[2]='F')
				n[2]=1;
	else;
				n[2]=0;	
		if(s1[2]='A')
			if(s1[2]='B')
				n[3]=1;
	else;
				n[3]=0;	

		if(s1[2]='C')
			if(s1[2]='B')
				n[3]=1;
	else;
				n[3]=0;	

		if(s1[2]='F')
			if(s1[2]='D')
				n[3]=1;
	else;
				n[3]=0;	
		cout<<n;
		return 0;
	fclose(stdin);
	fclose(stdout);
}
