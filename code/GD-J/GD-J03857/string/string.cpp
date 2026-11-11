#include<bits/stdc++.h>
using namespace std;
int x[211111];
char c[211111];
long long s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
			s+=min(x[l],x[r]);
		int a=x[l],b=x[r];
		x[l]-=min(a,b);
		x[r]-=min(a,b);
		if(x[l]<=0)
			l++;
		if(x[r]<=0)
			r--;
	}
	cout<<s;
	return 0;
}
