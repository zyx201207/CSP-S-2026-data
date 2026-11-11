#include<bits/stdc++.h>
using namespace std;
long long a[200005],sum;
int n;
string s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		int t=0;
		if(s[l]!=s[r])
		{
			t=1;
		}
		if(a[l]>a[r])
		{
			if(t==1)
			{
				sum+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r])
		{
			if(t==1)
			{
				sum+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		else
		{
			if(t==1)
			{
				sum+=a[l];
			}
			a[r]=0;a[l]=0;
			r--;l++;
		}
	}
	cout<<sum;
	return 0;
}
