#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a,b;
bool x,y;
bool flag=0,check=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		check=1;
		cout<<"1";
	}
	else cout<<"0";
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&check==1){
		flag=1;
		cout<<"1";
	}
	else cout<<"0";
	
	a=int(s1[2]-'A');
	b=int(s2[2]-'A');
	if(a>=3&&a<=4)x=1;
	if(b>=3&&b<=4)y=1;
	if(x==y&&flag==1&&check==1)cout<<"1";
	else cout<<"0";
	
	if(x==y&&abs(a-b)==1&&flag==1&&check==1)cout<<"1";
	else cout<<"0";
    return 0;
    //02 01C 02 01A
}
