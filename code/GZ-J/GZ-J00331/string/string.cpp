//GZ-J00311 贵阳市第三中学 杨鑫豪 
#include<bits/stdc++.h>
using namespace std;
long long n,l,r,a[200005],x,xx,ans;
char s[200005];
int main()
{
	
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i]>>s[i];
	}
	l=1;
	r=n;
	
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			if(a[l]>a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				ans+=a[r];
				l++;
				r--;
			}
			else
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				l++;
				r--;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
