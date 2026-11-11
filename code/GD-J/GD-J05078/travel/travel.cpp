#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=1;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)a=0;
	cout<<a;
	if(s1[0]!=s2[0]||s1[1]!=s2[1])a=0;
	cout<<a;
	if(!((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')))a=0;
	cout<<a;
	if(abs(int(s1[2])-int(s2[2]))!=1)a=0;
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
