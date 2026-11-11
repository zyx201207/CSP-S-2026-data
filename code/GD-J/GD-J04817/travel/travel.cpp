#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

bool aa(char a,char b){
	return abs(a-b)==1;
}
int main(){
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool q1=(c1==c2);
	bool q2=(q1&&s1[0]==s2[0]&&s1[1]==s2[1]);
	bool q3=(q2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')));
	bool q4=(q3&&(!(s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))&&aa(s1[2],s2[2]));
	cout<<q1<<q2<<q3<<q4<<endl;
	return 0;
}
