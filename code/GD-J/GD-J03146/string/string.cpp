#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
long long n,a[200005],ans;
char c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;)
	{
		if(c[i]!=c[j])
		{
			if(a[i]>a[j])
			{
				ans=ans+a[j];
				a[i]=a[i]-a[j];
				j--;
			}
			else
			{
				ans=ans+a[i];
				a[j]=a[j]-a[i];
				if(a[j]==0)
				{
					j--;
				}
				i++;
			}
		}
		else
		{
			if(a[i]<a[j])
			{
				a[j]=a[j]-a[i];
				i++;
			}
			else
			{
				a[i]=a[i]-a[j];
				j--;
				if(a[i]==0)
				{
					i++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
