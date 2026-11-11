//GZ-J00701 张景烁 兴义市弘毅中学 
#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long a,b;
cin >> a >> b;
long long e = 0;
int c[a];
for(int s = 0;s < a;s++)
{
	cin >> c[s];
 } 
for (int i = 0;i<b; i++)
{
for(int f =0;f < a;f++)
{
	if(c[f]>=e)
	{
		f = e;
	}
}
c[e] -= c[e];
}
cout << e <<endl;
return 0;
} 
