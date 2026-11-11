#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char x1=s1[2],x2=s2[2];
	int l1=(s1[0]-'0')*10+s1[1]-'0',l2=(s2[0]-'0')*10+s2[1]-'0';
	bool a1=(c1==c2),a2=(a1 && l1==l2),a3=(a2 && (('A'<=x1&&x1<='C' && 'A'<=x2&&x2<='C')||('D'<=x1&&x1<='E' && 'D'<=x2&&x2<='E'))),a4=(a3 && (x1==x2+1 || x2==x1+1));
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
