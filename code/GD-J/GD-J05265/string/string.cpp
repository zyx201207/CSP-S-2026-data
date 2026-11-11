#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
ll a[N],ans=0;
char c[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	int i=1,j=n;
	while(i<j)
	{
		if(c[i]!=c[j])
		{
			if(a[i]==a[j])
			{
				ans+=a[i];
				i++;
				j--;
			}
			else if(a[i]<a[j])
			{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
			else//ai>aj 
			{
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
		}
		else
		{
			if(a[i]==a[j])
			{
				i++;
				j--;
			}
			else if(a[i]<a[j])
			{
				a[j]-=a[i];
				i++;
			}
			else//ai>aj 
			{
				a[i]-=a[j];
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}













