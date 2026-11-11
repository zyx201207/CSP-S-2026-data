#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,s1,c2,s2;
	bool f1,f2,f3,f4;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) f1=1;
	else{
		cout<<"0000";
		return 0;	
	}
	if(s1[0]==s2[0] && s1[1]==s2[1] && f1==1) f2=1;
	else f2=0;
	if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C' && f2==1) f3=1;
	else if(s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F' && f2==1) f3=1;
	else f3=0;
	if(f3==1 && (int(s1[2]-s2[2])==1 || int(s2[2]-s1[2])==1)) f4=1;
	else f4=0;
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
