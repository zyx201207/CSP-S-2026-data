#include<bits/stdc++.h>
using namespace std;
long long a,s,d,f,cnt;
string qwe;
char q;
int main ()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin >> a;
for(long long i=0;i<a;i++)
{
	cin >> s >> q;
	for(int j=1;j<=s;j++)
	{
		qwe[d]=q;
		d++;
	}
}
f=d-1;
for(int i=0;i<d/2;i++)
{
	if(qwe[i]!=qwe[f])
	{
		cnt++;
	}
	f--;
}
cout<<cnt;
return 0;
}

