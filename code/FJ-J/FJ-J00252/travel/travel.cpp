#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,aa,bb;
	cin >> a >> aa >> b >> bb;
	char a1=aa[0],a2=aa[1],a3=aa[2],b1=bb[0],b2=bb[1],b3=bb[2];
	if(a==b) cout << 1;
	else cout << 0;
	if(a==b && a1==b1 && a2==b2) cout << 1;
	else cout << 0;
	if(a==b && a1==b1 && a2==b2 && (a3=='A' || a3=='B' || a3=='C')==(b3=='A' || b3=='B' || b3=='C')) cout << 1;
	else cout << 0;
	if(a==b && a1==b1 && a2==b2 && (a3=='A' || a3=='B' || a3=='C')==(b3=='A' || b3=='B' || b3=='C') && (a3-b3==1 || b3-a3==1)) cout << 1;
	else cout << 0;
	return 0;
}
