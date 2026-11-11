#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string c1,c2; 
bool p,pp;
char c,cc;
int a,b;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<1;
	a=int(s1[0]-'0')*10+int(s1[1]-'0');
	b=int(s2[0]-'0')*10+int(s2[1]-'0');
	if(a!=b){
		cout<<"000"<<endl;
		return 0;
	}
	cout<<1;
	c=s1[2];
	cc=s2[2];
	if(c=='A'||c=='B'||c=='C')p=1;
	if(cc=='A'||cc=='B'||cc=='C')pp=1;
	if((p==1&&pp==1) ||(p==0&&pp==0))cout<<1;
	else{
		cout<<"00"<<endl;
		return 0;
	}
	if(p&&pp){
		if(c=='A'&&cc=='C')cout<<0<<endl;
		else if(cc=='A'&&c=='C')cout<<0<<endl;
		else cout<<1<<endl;
	}
	else cout<<1<<endl;
	
	return 0;
} 
