#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
		
	}
	
	if(s1[0]+s1[1]==s2[0]+s2[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	
	int num1=s1[2]-'a',num2=s2[2]-'a';
	
	if((num1<=2&&num2<=2)||(!num1<=2&&!num2<=2)) cout<<1;
	else{
		cout<<"00";
		return 0;
		
	}
	
	if(abs(num1-num2)==1) cout<<1;
	else cout<<0;
	return 0;
}