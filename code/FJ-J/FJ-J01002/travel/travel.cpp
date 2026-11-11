#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int n1=0,n2=0;
	cin>>c1>>s1>>c2>>s2;
	
	if(s1[2]>='A'&&s1[2]<='C')
		n1=1;
	if(s2[2]>='A'&&s2[2]<='C')
		n2=1;
	if(c1==c2)
		cout<<1;
	else
		cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2)
		cout<<1;
	else
	    cout<<0;
	if(n1==n2&&s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2)
		cout<<1;
	else
		cout<<0;
		

			
	if(abs(int(s1[2]-s2[2]))==1&&n1==n2&&s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2)
		cout<<1;
	else
		cout<<0;
 	return 0;
} 
