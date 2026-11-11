#include<bits/stdc++.h>
using namespace std;
struct qq{
	long long x;
	char y;
};
long long n;
qq a[200005];
string b;
long long q;
long long s;
long long l;
long long r;
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	
	for(long long i = 1;i <= n;++i)
	{
		cin >> a[i].x >> a[i].y;
		q+=a[i].x;
		for(long long j = 1;j <= a[i].x;++j)
		{
			b+=a[i].y;
		}
	}
	r = q-1;
	while(l<=r)
	{
		if(b[l]!=b[r])
		{
			s++;
		}
		l++;
		r--;
	}
	cout << s;
	return 0;
}
