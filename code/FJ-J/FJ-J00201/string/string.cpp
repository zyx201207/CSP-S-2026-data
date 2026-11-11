#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char p[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>p[i];
	int l=1,r=n;
	while(l<r)
	{
		if(a[l]==a[r])
		{
			if(p[l]!=p[r])ans+=a[r];
			l++,r--;
		}
		if(a[l]>a[r])
		{
			if(p[l]!=p[r])ans+=a[r];
			a[l]-=a[r];r--;
		}
		if(a[l]<a[r])
		{
			if(p[l]!=p[r])ans+=a[l];
			a[r]-=a[l];l++;
		}
		//cout<<l<<" "<<r<<endl;
	}
	cout<<ans;
	return 0;
}
