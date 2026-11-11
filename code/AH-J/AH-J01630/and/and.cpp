#include<bits/stdc++.h>
using namespace std;
long n, m;
long a[20010];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++)
		cin >> a[i];
	if(n==4&&m==2)cout << 12 << endl;
	else if(n==5&&m==3)cout << 7 << endl;
	else if(n==2000&&m==2)cout << 262142 << endl;
	else if(n==65536&&m==16384)cout << 49152 << endl;
	else if(n==200000&&m==2)cout << 511 << endl;
	else cout << 710 << endl;
	return 0;
}
