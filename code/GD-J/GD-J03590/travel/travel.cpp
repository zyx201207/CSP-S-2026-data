#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char num1,num2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	num1=s1.back(),num2=s2.back();
	s1.pop_back(),s2.pop_back();
	cout<<(c1==c2);
	cout<<(c1==c2&&s1==s2);
	cout<<(c1==c2&&s1==s2&&((num1<='C'&&num2<='C')||(num1>'C'&&num2>'C')));
	cout<<(c1==c2&&s1==s2&&abs((int)(num1-num2))==1&&!(num1=='C'&&num2=='D')&&!(num2=='C'&&num1=='D'));
	return 0;
}
