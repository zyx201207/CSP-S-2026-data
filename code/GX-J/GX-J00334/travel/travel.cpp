#include<bits/stdc++.h>
using namespace std;
int a[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travle.out","w",stdout);
	string c1,s1,c2,s2;
	
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]) {
		a[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			a[1]=1;
			if((char(s1[2])<='C'&&char(s2[2])<='C')||(char(s1[2])>'C'&&char(s2[2])>'C'&&char(s1[2])<='F'&&char(s2[2])<='F')) {
				a[2]=1;
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1) {
					a[3]=1;
				}	
				else a[3]=0;
			}					
			else a[2]=0;	
		}			
		else a[1]=0;	
	}		
	else a[0]=0;
	for(int i=0;i<4;i++) cout<<a[i];
		
	return 0;
}	
