#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
inline int read(){
	int f=1,g=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		g=(g<<3)+(g<<1)+(c-'0');
		c=getchar();
	}
	return f*g;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar((x%10)+'0');
	return ;
}
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
bool func1(string s,string t){
	if(s.substr(0,2)==t.substr(0,2))return true;
	return false;
}
bool func2(string s,string t){
	int l=0,r=0;
	if(s[2]=='A'||s[2]=='B'||s[2]=='C')l=1;
	else l=2;
	if(t[2]=='A'||t[2]=='B'||t[2]=='C')r=1;
	else r=2;
	if(l==r)return true;
	return false;
}
bool func3(string s,string t){
	if(s[2]=='D'||s[2]=='F'){
		if(t[2]=='D'||t[2]=='F')return true;
		return false;
	}
	else{
		if(s[2]=='A'&&t[2]=='B')return true;
		else if(s[2]=='B'&&t[2]=='C')return true;
		else if(s[2]=='B'&&t[2]=='A')return true;
		else if(s[2]=='C'&&t[2]=='B')return true;
		return false;
	}
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("traval.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)f1=1;
	if(f1&&func1(s1,s2))f2=1;
	if(f1&&f2&&func2(s1,s2))f3=1;
	if(f1&&f2&&f3&&func3(s1,s2))f4=1;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
