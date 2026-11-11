#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
long long ans;
int main()
{

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n;
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i]; 
	}
	for(i=1,j=n;i<j;)
	{
		if(c[i]!=c[j])
		{
			ans+=min(a[i],a[j]);
		}
		if(a[i]>a[j])
		{
			a[i]-=a[j];
			j--;
		}	
		else if(a[i]==a[j])
		{
			i++;
			j--;
		}
		else
		{
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}
