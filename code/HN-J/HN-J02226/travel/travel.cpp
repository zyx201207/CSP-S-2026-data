#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string a,b,c,d;

void oc()
{
	string s = ""+b[0]+b[1],s1=""+d[0]+d[1];
    if(a==c)cout << 1;
    else cout << 0;
    if(a==c && s==s1) cout << 1;
    else cout <<0;
    if(a==c && s==s1 && (b[2]<='C'&&d[2]<='C' || b[2]>='D'&&d[2]>='D')) cout << 1;
    else cout << 0;
	if(a==c && s==s1 && (b[2]<='C'&&d[2]<='C' || b[2]>='D'&&d[2]>='D')&&(b[2]+1==d[2] || b[2]-1==d[2])) cout << 1;
	else cout << 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	oc();
	
}
