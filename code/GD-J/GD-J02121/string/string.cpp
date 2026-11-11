#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
long long  n,m,k,sum,ans;
long long  a[N];
char s[N];
char h;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	long long i=1,j=n;
	while(i<j)
	{
		if(s[i]==s[j]) 
		{
			k=min(a[i],a[j]);
			if(a[i]>a[j]) 
			{
				a[i]-=k;
				j--;
			}
			else if(a[i]<a[j]) 
			{
				a[j]-=k;
				i++;
			}
			else if(a[i]==a[j])
			{
				i++;
				j--;
			}
		} 
		else 
		{
			ans+=min(a[i],a[j]);
			k=min(a[i],a[j]);
			if(a[i]>a[j]) 
			{
				a[i]-=k;
				j--;
			}
			else if(a[i]<a[j]) 
			{
				a[j]-=k;
				i++;
			}
			else if(a[i]==a[j])
			{
				i++;
				j--;
			}
		}
		//cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<" "<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
