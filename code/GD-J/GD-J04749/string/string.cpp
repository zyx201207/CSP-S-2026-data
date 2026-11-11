#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
string b[200005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int head=0,tail=n-1;
	while(head<=tail)
	{
		if(b[head]==b[tail])
		{
			if(a[head]>=a[tail])
			{
				a[head]-=a[tail];
				tail--;
			}
			else
			{
				a[tail]-=a[head];
				head++;
			}
		}
		else
		{
			if(a[head]>=a[tail])
			{
				ans+=a[tail];
				a[head]-=a[tail];
				tail--;
			}
			else
			{
				ans+=a[head];
				a[tail]-=a[head];
				head++;
			}
		}
	}
	cout<<ans;
	return 0;
}
