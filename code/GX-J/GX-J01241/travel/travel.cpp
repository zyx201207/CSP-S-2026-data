#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
int a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) 
	{
		a=1;
		if(s1[1]==s2[1] && s1[0]==s2[0])
		{
			b=1;
			if(s1[2]<='C' && s1[2]>='A' && s2[2]<='C' && s2[2]>='A')
			{
				c=1;
				if(s1[2]=='B' || s2[2]=='B') d=1;
			}
			else if(s1[2]<='E' && s1[2]>='D' && s2[2]<='E' && s2[2]>='D') c=1,d=1;
		}
	}
	
		cout<<a<<b<<c<<d;
	
    return 0;
}
