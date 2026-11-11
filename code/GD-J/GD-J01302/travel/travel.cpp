#include<bits/stdc++.h>
using namespace std;
int c1,c2,n1,n2;
string s1,s2,g1,g2,p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	n1=s1.size(),n2=s2.size();
	p1=s1.substr(0,n1-1),p2=s2.substr(0,n2-1);
	g1=s1.substr(n1-1,1),g2=s2.substr(n2-1,1);
	if(c1!=c2) cout<<"0000";
	else if(p1!=p2) cout<<"1000";
	else if(((g1>="A"&&g1<="C")&&(g2>="D"&&g2<="F"))||((g2>="A"&&g2<="C")&&(g1>="D"&&g1<="F")))
			cout<<"1100";
	else if((g1>="A"&&g1<="C")&&((g1=="A"&&g2=="C")||(g2=="A"&&g1=="C"))) cout<<"1110";
	else cout<<"1111";
	return 0;
}
