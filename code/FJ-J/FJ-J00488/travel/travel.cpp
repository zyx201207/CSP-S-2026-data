#include <bits/stdc++.h>
using namespace std;

string s1,c1,s2,c2;
int a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>s1>>c1>>s2>>c2;

	a=10*(s1[0]-'0')+(s1[1]-'0');
	b=10*(s2[0]-'0')+(s2[1]-'0');
	
	if (a!=b) cout<<"0000";
	else{
		c=10*(c1[0]-'0')+(c1[1]-'0');
		d=10*(c2[0]-'0')+(c2[1]-'0');
		if (c!=d) cout<<"1000";
		else{
			if (c1[2]>c2[2]) swap(c1[2],c2[2]);
			if ((c1[2]=='A'||c1[2]=='B'||c1[2]=='C')
				&&(c2[2]=='D'||c2[2]=='F'))
				cout<<"1100";
			else{
				if (c1[2]=='A'&&c2[2]=='C') cout<<"1110";
				else cout<<"1111";
			}
		}
	}
	
	return 0;
}
