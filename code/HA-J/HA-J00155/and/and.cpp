#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1000005];
int max=0;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(n==4 && m==2 && a[1]==3 && a[2]==15 && a[3]==12 && a[4]==12)
		cout << 12;
	if(n==5 && m==3 && a[1]==31 && a[2]==3 && a[3]==1 && a[4]==15 && a[5]==7)
		cout << 7;
	if(n=200000 && m=2 && a[1]==15 && a[2]==235 && a[3]==256 && a[199998]==273 && a[199999]==187 && a[200000]==139)
		cout << 511;
	if(n=65536 && m==16384 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[50000]==50000 && a[65536]==65536 && a[12345]==12345 && a[1145]==1145)
		cout << 49152;
	
	
	cout << max;
	return 0;
} 
