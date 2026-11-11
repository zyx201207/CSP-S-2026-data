#include <bits/stdc++.h>
using namespace std;
long long sum=0;
struct Leter
{
	int a;
	char c;
} s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a;
		cin>>s[i].c;
	}
	int l=1,r=n;
	while(l<r)
	{
		long long tmp=min(s[l].a,s[r].a);
		s[l].a-=tmp;
		s[r].a-=tmp;
		if(s[l].c != s[r].c)
			sum+=tmp;
		if(s[l].a==0) l++;
		if(s[r].a==0) r--;
	}
	cout<<sum;
	return 0;
}
