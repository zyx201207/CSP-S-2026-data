#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int a,b;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	char c1=s1[2],c2 = s2[2];
	int d1=(s1[0]-'0')+(s1[1]-'0');
	int d2=(s2[0]-'0')+(s2[1]-'0');
	int x=abs(int(c2-c1));
	if(a==b) f1 = 1;
	if(d1==d2&&f1) f2=1;
	if(((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C'))&&f2) f3=1;
	if(x == 1&&f3) f4=1;
	cout<<f1<<f2<<f3<<f4;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
