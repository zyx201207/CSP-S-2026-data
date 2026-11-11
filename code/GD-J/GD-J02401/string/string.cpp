#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int have;
	char c;
}a[200005];
priority_queue<int>q;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans;
	ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i].have>>a[i].c;
	int i=1,j=n;
	for (;i<j;)
		{
		//cout<<i<<' '<<j<<' '<<a[i].have<<' '<<a[j].have<<endl;
		if (a[i].have==a[j].have)
			{
			if (a[i].c!=a[j].c)ans+=a[i].have;
			i++,j--;
			}
		else if (a[i].have>a[j].have)
				{
				if (a[i].c!=a[j].c)
					ans+=a[j].have;
				a[i].have-=a[j].have;
				j--;
				}
		else if (a[i].have<a[j].have)
				{
				if (a[i].c!=a[j].c)
					ans+=a[i].have;
				a[j].have-=a[i].have;
				i++;
				}
		//cout<<i<<' '<<j<<' '<<a[i].have<<' '<<a[j].have<<endl<<endl;
		}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

