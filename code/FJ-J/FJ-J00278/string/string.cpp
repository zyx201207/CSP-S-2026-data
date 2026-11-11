#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i]; 
	}
	int i=1,j=n;
	while(i<j)
	{
		int k=min(a[i],a[j]);
		if(c[i]!=c[j]) ans+=k;
		a[i]-=k;
		a[j]-=k;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<ans;
	return 0;
}
