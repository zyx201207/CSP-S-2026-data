#include<iostream>
using namespace std;
string c1,c2,s1,s2;
int trans[12];
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	trans[0]=trans[1]=trans[2]=1;
	trans[3]=trans[5]=2;
	cin>>c1>>s1>>c2>>s2;
	a=(c1==c2);
	b=(s1.substr(0,2)==s2.substr(0,2));
	c=(trans[s1[2]-'A']==trans[s2[2]-'A']);
	d=( (trans[s1[2]-'A']==2&&trans[s2[2]-'A']==2) || s1[2]-s2[2]==1 || s1[2]-s2[2]==-1 );
	cout<<a<<(a&b)<<(a&b&c)<<(a&b&c&d);
	return 0;
} 
