#include<bits/stdc++.h> 
using namespace std;
int n;
long long a[200001],ans=0;
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int j=n;
	for(int i=1;i<j;i++)
	{
		if(c[i]!=c[j])
		{
		if(a[i]==a[j])
		{
			ans+=a[i];
			j--;
		}
		else if(a[i]>a[j])
		{
			ans+=a[j];
			a[i]=a[i]-a[j];
			j--;
			i--;
		}
		else{
			ans+=a[i];
			a[j]=a[j]-a[i];
		}
		}
		else{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				j--;
				i--;
			}
			else if(a[i]==a[j])
			{
				j--;
			}
			else{
				a[j]-=a[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
