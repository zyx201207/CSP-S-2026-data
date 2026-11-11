#include<bits/stdc++.h>
using namespace std;
int a[200005];
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	long long cnt=0;
	long long temp=0,l=1,r=n; 
	while(temp<sum/2)
	{
		if(a[l]==a[r]&&s[l]==s[r]) 
		{
			temp+=a[l];
			l++;
			r--;
		}
		else if(a[l]==a[r]&&s[l]!=s[r])
		{
			temp+=a[l];
			cnt+=a[l];
			l++;
			r--;
		}
		else if(a[l]<a[r]&&s[l]==s[r])
		{
			temp+=a[l];
			a[r]-=a[l];
			l++;
		}
		else if(a[l]<a[r]&&s[l]!=s[r])
		{
			cnt+=a[l];
			temp+=a[l];
			a[r]-=a[l];
			l++;
		}
		else if(a[l]>a[r]&&s[l]==s[r])
		{
			temp+=a[r];
			a[l]-=a[r];
			r--;
		}
		else if(a[l]>a[r]&&s[l]!=s[r])
		{
			cnt+=a[r];
			temp+=a[r];
			a[l]-=a[r];
			r--;
		}
	}
	cout<<cnt;
	return 0;
}
