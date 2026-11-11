#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else {cout<<"0000"; return 0;}
	string l1,l2;
	l1=c1[0]+c1[1];
	l2=c2[0]+c2[1];
	if(l1==l2) cout<<"1";
	else {cout<<"000";return 0;}
	l1=s1[2];
	l2=s2[2];
	if(((l1=="A"||l1=="B"||l1=="C")&&(l2=="A"||l2=="B"||l2=="C"))||((l1=="D"||l1=="E")&&(l2=="D"||l2=="E"))) cout<<"1";
	else {cout<<"00";return 0;}
	if(((l1=="A"||l1=="B")&&(l2=="A"||l2=="B"))||((l1=="B"||l1=="C")&&(l2=="B"||l2=="C"))||((l1=="D"||l1=="E")&&(l2=="D"||l2=="E"))) cout<<"1";
	else cout<<"0";
	return 0;
}
