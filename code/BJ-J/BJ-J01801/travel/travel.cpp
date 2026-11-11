#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string n,m;
int a,b;
cin >> a >> n >> b >> m;
if(a != b)
cout << 0000;
else if(n[1] * 10 + n[2] != m[1] * 10 + m[2])
cout << 1000;
else if((n[3] == 'A' && m[3] == 'B') || (n[3] == 'B' && m[3] == 'A') || (n[3] == 'C' && m[3] == 'B') || (n[3] == 'B' && m[3] == 'C') || (n[3] == 'D' && m[3] == 'F') || (n[3] == 'F' && m[3] == 'D'))
cout << 1111;
else
cout << 1110;
return 0;
}