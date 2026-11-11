#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","t",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2);
	cout<<(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2);
	cout<<(((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C'))&&(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2));
	cout<<((s1[0]==s2[0]&&s1[1]==s2[1]&&(((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C'))&&abs(s1[2]-s2[2])==1))||(s1[2]==s2[2]&&abs(((s1[0]-'0')*10+s1[1]-'0')-((s2[0]-'0')*10+s2[1]-'0'))==1));
	return 0;
}
