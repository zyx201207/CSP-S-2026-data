#include<bits/stdc++.h>
using namespace std;
char a[20];
bool b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<13;i++) scanf("%c",&a[i]);
	b=(a[0]==a[7]&&a[1]==a[8]),c=(a[3]==a[10]&&a[4]==a[11]&&b),d=(((a[5]<=67&&a[12]<=67)||(a[5]>67&&a[12]>67))&&c);
	cout<<b<<c<<d<<(abs(a[5]-a[12])==1&&d);
	return 0;
}
