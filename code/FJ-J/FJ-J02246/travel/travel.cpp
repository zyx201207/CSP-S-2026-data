#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a,b;
string aw,bw;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> aw >> b >> bw;
	if(a!=b)
		cout << 0 << 0 << 0 << 0;
	else if(aw[0]!=bw[0]||aw[1]!=bw[1])
		cout << 1 << 0 << 0 << 0;
	else if(aw[2]>='A'&&aw[2]<='C'&&bw[2]>='D'&&bw[2]<='F'||aw[2]>='D'&&aw[2]<='F'&&bw[2]>='A'&&bw[2]<='C')
		cout << 1 << 1 << 0 << 0;
	else if(aw[2]<='C'&&bw[2]<='C'&&abs((aw[2]-'A')-(bw[2]-'A'))>1)
		cout << 1 << 1 << 1 << 0;
	else
		cout << 1 << 1 << 1 << 1;
	return 0;
}
