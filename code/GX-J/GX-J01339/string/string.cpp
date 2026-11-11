#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string a;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		long long u;
		string c;
		cin>>u>>c;
		for(long long j=0;j<u;j++)
		{
			a+=c;
		}
	}
	long long head=0,tail=a.size()-1,ans=0;
	while(head<=tail)
	{
		if(a[head]!=a[tail])
		{
			ans++;
		};
		head++;
		tail--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
