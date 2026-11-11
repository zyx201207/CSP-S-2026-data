#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
char c[8]={' ','y','y','y','*','n','n',' '};
void p(string a,string b,string c,string d)
{
	if(a==b) cout<<"1";
	else
	{
		cout<<"0000";
		return ;
	}
	int str1=0,str2=0;
	str1+=((int)(c[0]-'0'))*10+((int)(c[1]-'0'));
	str2+=((int)(d[0]-'0'))*10+((int)(d[1]-'0'));
	if(str1==str2) cout<<"1";
	else
	{
		cout<<"000";
		return ;
	}
	int h1=0,h2=0;
	h1=(int)(c[2]-'A')+1; 
	h2=(int)(d[2]-'A')+1;
	if(((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((c[2]=='D'||c[2]=='F')&&(d[2]=='D'||d[2]=='F'))) cout<<"1";
	else
	{
		cout<<"00";
		return ;
	}
	if(c[h1+1]==c[h2]||c[h1-1]==c[h2]||c[h2+1]==c[h1]||c[h2-1]==c[h1]) 
	{
		cout<<"1";
		return ;
	}
	cout<<"0";
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);	
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	p(c1,c2,s1,s2);
	return 0;
} 
