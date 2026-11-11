#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(char f,char e)
{

	if((f>='A'&&f<='C'&&e>='A'&&e<='C')||(f>='D'&&f<='E'&&e>='D'&&e<='E'))return 1;
	return 0;
}
bool f(char o1,char o2)
{
	if(o1=='A'&&o2=='B')return 1;
	if(o1=='B'&&(o2=='A'||o2=='C'))return 1;
	if(o1=='C'&&o2=='B')return 1;
	if(o1=='D'&&o2=='E')return 1;
	if(o1=='E'&&o2=='D')return 1;
	return 0;
	
 } 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<0;
	else cout<<1;
	int x,y;
	x=(s1[0]-'0')*10+s1[1]-'0';
	y=(s2[0]-'0')*10+s2[1]-'0';
	if(x==y&&c1==c2)cout<<1;
	else cout<<0;
	char a,b;
	a=s1[2],b=s2[2];
	if(check(a,b)&&x==y&&c1==c2)cout<<1;
	else cout<<0;
	if(check(a,b)&&x==y&&f(a,b)&&c1==c2)
	{
		cout<<1;
	}
	else cout<<0;
	
	return 0;
} 
