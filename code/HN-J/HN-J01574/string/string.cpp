#include<bits/stdc++.h>
using namespace std;
long long n,s=0;
long long a[100005];
char b[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1,j=n;i<=j;)
	{
		s+=min(a[j],a[i]);
		if(a[i]>a[j])
		{		
			a[i]-=a[j];
			j--;
		}
		else if(a[i]<a[j])
		{
			a[j]-=a[i];
			i++;
		}
		else
		{
			i++;
			j--;
		}
	}
	cout<<s;
	return 0;
}
