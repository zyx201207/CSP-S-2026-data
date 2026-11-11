#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool f1,f2,f3;
bool check(string s1,string s2)
{
	char a=s1[2],b=s2[2];
	if(a=='A' && b=='B') return true;
	if(a=='B' && b=='A') return true;
	if(a=='B' && b=='C') return true;
	if(a=='C' && b=='B') return true;
	if(a=='D' && b=='F') return true;
	if(a=='F' && b=='D') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	f1=f2=f3=false;
	if(c1==c2) f1=true;
	if(s1[0]==s2[0] && s1[1]==s2[1] && f1) f2=true;
	if((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C' && f2) || (s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F' && f2)) f3=true;
	cout<<f1<<f2<<f3;
	if(f1 && f2 && f3 && check(s1,s2)) cout<<1;
	else cout<<0;
	return 0;
} 
