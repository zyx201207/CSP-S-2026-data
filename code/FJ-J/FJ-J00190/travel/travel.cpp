#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cone,sone;
	string c,s;
	cin>>cone>>c>>sone>>s;
	if(cone==sone)//同一车厢 t
	cout<<1;
	else{cout<<0<<0<<0<<0;return 0;
	}
	if(s[1]==c[1]&&s[0]==c[0])//同一排 
	cout<<1;
	else{cout<<0<<0<<0;return 0;
	}
	
	if((s[2]=='A'&&(c[2]=='B'||c[2]=='C'))||
	   (s[2]=='B'&&(c[2]=='A'||c[2]=='C'))||
	   (s[2]=='C'&&(c[2]=='B'||c[2]=='A'))||
	   (s[2]=='D'&& c[2]=='F')||
	   (s[2]=='F'&& c[2]=='D'))//同一侧 f
	cout<<1;
	else
	cout<<0;
	if((s[2]=='A'&&c[2]=='B')||
	   (s[2]=='B'&&(c[2]=='A'||c[3]=='C'))||
	   (s[2]=='C'&&c[2]=='B')||
	   (s[2]=='D'&&c[2]=='F')||
	   (s[2]=='F'&&c[2]=='D'))//相邻f
	cout<<1;
	else
	cout<<0;
	return 0;
}
