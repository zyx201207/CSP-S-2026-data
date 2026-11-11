#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x=c1==c2;
	cout<<x;
	x=x&&s1[0]==s2[0]&&s1[1]==s2[1];
	cout<<x;
	x=x&&(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'));
	cout<<x;
	x=x&&(abs(s1[2]-s2[2])==1&&((s1[2]!='C'&&s2[2]!='D')||(s1[2]!='D'&&s2[2]!='C')));
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
