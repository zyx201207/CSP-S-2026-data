#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int f1=(c1==c2);
	int a=0,b=0;
	char x,y;
	for(int i=0;i<s1.size()-1;i++){
		a=a*10+s1[i]-'0';
	}
	x=s1[s1.size()-1];
	for(int i=0;i<s2.size()-1;i++){
		b=b*10+s2[i]-'0';
	}
	y=s2[s2.size()-1];
	int f2=(a==b)&&f1;
	int f3=f2&&(x>='A'&&x<='C'&&y>='A'&&y<='C'||x>='D'&&x<='F'&&y>='D'&&y<='F')&&(x!=y);
	int f4=f2&&(abs((int)x-(int)y)==1)&&f3;
	printf("%d%d%d%d",f1,f2,f3,f4);
	return 0;
}
