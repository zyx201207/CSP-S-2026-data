#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f1=0,f2=0,f3=0,f4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)f1=1;
	char h1=s1[2];
	char h2=s2[2];
	if(f1&&s1[0]==s2[0]&&s1[1]==s2[1])f2=1;
	if(f2&&'A'<=h1&&h1<='C'&&'A'<=h2&&h2<='C'||f2&&'D'<=h1&&h1<='F'&&'D'<=h2&&h2<='F')f3=1;
	if(f3&&abs(h1-h2)==1||f3&&h1=='D'&&abs(h1-h2)==2||f3&&h2=='D'&&abs(h1-h2)==2)f4=1;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
