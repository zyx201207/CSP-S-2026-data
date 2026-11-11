#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	int a=0,b=0,c=0,d=0;
	cin>>c1>>c2>>c3>>c4;
	if(c1[0]==c3[0]&&c1[1]==c3[1]){
	cout<<1;
	
	if(c2[0]==c4[0]&&c2[1]==c4[1]||c2[2]==c4[2]){
	cout<<1;
	if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'&&c4[2]=='A'||c4[2]=='B'||c4[2]=='C')
	{
	cout<<1;
	a=(c2[0]-'0')*10;b=(c4[0]-'0')*10;c=c2[1]-'0';d=c4[1]-'0';
	if(c2[2]-c4[2]==1||c4[2]-c2[2]==1||a+c-b-d==1||b+d-a-c==1)cout<<1;
	else cout<<0;
	}
	
	else if(c2[2]=='D'||c2[2]=='F'&&c4[2]=='D'||c4[2]=='F'){
	cout<<1;
	a=(c2[0]-'0')*10;b=(c4[0]-'0')*10;c=c2[1]-'0';d=c4[1]-'0';
	if(c2[2]-c4[2]==1||c4[2]-c2[2]==1||a+c-b-d==1||b+d-a-c==1)cout<<1;
	else cout<<0;
	}
	
	else cout<<0<<0; 
	}
	else cout<<0<<0<<0;
}
	else cout<<0<<0<<0<<0;
	
	return 0;
 } 
