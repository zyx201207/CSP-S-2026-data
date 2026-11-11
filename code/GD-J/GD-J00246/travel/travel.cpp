#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x=x+s1[0]+s1[1];y=y+s2[0]+s2[1];
	char p1=s1[2],p2=s2[2];
	bool f1=(c1==c2),f2=(x==y),f3=(('A'<=p1)&&(p1<='C')&&('A'<=p2)&&(p2<='C'))||((('D'<=p1)&&(p1<='F')&&('D'<=p2)&&(p2<='F')));
	cout<<f1<<(f1&&f2)<<(f1&&f2&&f3)<<(f1&&f2&&f3&&(abs((int)(p1-p2))==1));
	return 0;
} 
