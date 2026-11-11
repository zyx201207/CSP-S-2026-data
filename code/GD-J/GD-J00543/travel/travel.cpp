#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int getPreTwo(string &x){
	return (x[0]-'0')*10+(x[1]-'0');
}
int getAside(char &a,char &b){
	return (a<='C'&&b<='C')||(a>='D'&&b>='D');
}
int getNeighbour(char a,char b){
	if(a>b)	swap(a,b);
	if(b=='F')	b='E';
	return a+1==b;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int c1int=getPreTwo(c1),c2int=getPreTwo(c2);
	int s1int=getPreTwo(s1),s2int=getPreTwo(s2);
	char seat1=s1[2],seat2=s2[2];
	bool flag=(c1int==c2int);
	cout<<flag;
	flag&=(s1int==s2int);
	cout<<flag;
	flag&=getAside(seat1,seat2);
	cout<<flag;
	flag&=getNeighbour(seat1,seat2);
	cout<<flag;
	return 0;
}
/*
13 08F 13 08D
*/
