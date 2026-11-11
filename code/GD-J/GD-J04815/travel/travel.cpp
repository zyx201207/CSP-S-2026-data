#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int l1=0,l2=0;
	for(int i=0;i<3&&s1[i]>='0'&&s1[i]<='9';++i)l1=l1*10+(s1[i]-'0');
	for(int i=0;i<3&&s2[i]>='0'&&s2[i]<='9';++i)l2=l2*10+(s2[i]-'0');
	char op1=s1[2],op2=s2[2];
	
	if(c1==c2)cout<<1;
	else cout<<0;
	
	if(c1==c2&&l1==l2)cout<<1;
	else cout<<0;
	
	if(((op1<='C'&&op2<='C')||(op1>'C'&&op2>'C'))&&l1==l2&&c1==c2)cout<<1;
	else cout<<0;
	
	if(((op1<='C'&&op2<='C')||(op1>'C'&&op2>'C'))&&abs((int)(op1-op2))==1&&l1==l2&&c1==c2)cout<<1;
	else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
