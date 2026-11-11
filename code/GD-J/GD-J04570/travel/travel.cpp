#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("travel"".in");
	ofstream out("travel"".out");
	//
	int c1,s1,c2,s2,a1,a2;
	string t1,t2;
	in>>c1>>t1>>c2>>t2;
	s1=(t1[0]-'0')*10+t1[1]-'0';
	s2=(t2[0]-'0')*10+t2[1]-'0';
	a1=t1[2]-'A';
	a1+=(a1==3?1:0);
	a2=t2[2]-'A';
	a2+=(a2==3?1:0);
	out<<(c1==c2);
	out<<((c1==c2)&&(s1==s2));
	out<<((c1==c2)&&(s1==s2)&&((a1<3&&a2<3)|(a1>3&&a2>3)));
	out<<((c1==c2)&&(s1==s2)&&(max(a1-a2,a2-a1)==1));
	return 0;
}
