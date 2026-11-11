#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2,ans;
bool book=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2) ans=ans+'1';
	else{
		printf("0000");
		return 0;
	} 
	if(book&&(b1[0]==b2[0]&&b1[1]==b2[1])) ans=ans+'1';
	else{
		printf("1000");
		return 0;
	} 
	if(book&&(!(b1[2]>'C')^(b2[2]>'C'))) ans=ans+'1';
	else{
		printf("1100");
		return 0;
	} 
	if(book&&(b1[2]-b2[2]==1||b1[2]-b2[2]==-1)) ans=ans+'1';
	else{
		printf("1110");
		return 0;
	}	
	cout<<ans;
	return 0;
} 
