#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,o;
	string h;
	cin>>a;
	for(long long i=1;i<=a;i++)
	{
		long long b;
		char c;
		cin>>b>>c;
		for(int p=1;p<=b;p++)h+=c;
		o+=b;
	}
	long long j=0;
	for(long long i=0;i<o/2;i++)
	{
		if(h[i]!=h[o-2-i])
		{
			j+=1;
		}
	}
	cout<<j;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
