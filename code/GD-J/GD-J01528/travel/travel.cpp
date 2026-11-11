#include<iostream> 
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string row1=s1.substr(0,2),row2=s2.substr(0,2);
	char seat1=s1[2],seat2=s2[2];
	if(c1!=c2) cout<<"0000";
	else if(row1!=row2) cout<<"1000";
	else if(!(seat1=='A'&&seat2=='B'||seat1=='A'&&seat2=='C'||seat1=='B'&&seat2=='C'||seat1=='B'&&seat2=='A'||seat1=='C'&&seat2=='A'||seat1=='C'&&seat2=='B'||seat1=='D'&&seat2=='F'||seat1=='F'&&seat2=='D')) cout<<"1100";
	else if(seat1=='A'&&seat2=='C'||seat1=='C'&&seat2=='A') cout<<"1110";
	else cout<<"1111";
	return 0;
}
