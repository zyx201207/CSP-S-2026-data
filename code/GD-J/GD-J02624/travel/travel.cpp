#include<iostream>
using namespace std;
struct zw
{
	string c;
	string w;
}s[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin >> s[1].c >> s[1].w >> s[2].c >> s[2].w ;
	if(s[1].c==s[2].c)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	if(s[1].w[0]==s[2].w[0]&&s[1].w[1]==s[2].w[1])
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	if((s[1].w[0]==s[2].w[0]&&s[1].w[1]==s[2].w[1]) &&(((s[1].w[2]=='F'||s[1].w[2]=='D')&&(s[2].w[2]=='D'||s[2].w[2]=='F'))||((s[1].w[2]=='A'||s[1].w[2]=='B'||s[1].w[2]=='C')&&(s[2].w[2]=='A'||s[2].w[2]=='B'||s[2].w[2]=='C'))))
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
    if((s[1].w[0]==s[2].w[0]&&s[1].w[1]==s[2].w[1]) &&( ((s[1].w[2]=='F'&&s[2].w[2]=='D')||(s[1].w[2]=='D'&&s[2].w[2]=='F'))||((s[1].w[2]=='A'&&s[2].w[2]=='B')||(s[1].w[2]=='B'&&s[2].w[2]=='A'))||((s[1].w[2]=='B'&&s[2].w[2]=='C')||(s[1].w[2]=='C'&&s[2].w[2]=='B'))))
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}	
    return 0;	
} 
