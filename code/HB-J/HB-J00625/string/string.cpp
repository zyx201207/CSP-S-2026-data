#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010];
long long ans=0;
long long cnt=0;
int main()
{   
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	int i=1,j=n;
	while(cnt!=0&&cnt!=1&&i!=j)
	{
		if(a[i]>a[j])
		{
			if(c[i]!=c[j])
			{
				ans+=a[j];
			}
			a[i]-=a[j];
			cnt-=2*a[j];
			j--;
		}
		else if(a[j]>a[i])
		{
			if(c[i]!=c[j])
			{
				ans+=a[i];
			}
			a[j]-=a[i];
			cnt-=2*a[i];
			i++;
		}
		else
		{
			if(c[i]!=c[j])
			{
				ans+=a[j];
			}
			cnt-=2*a[i];
			i++;
			j--;
		}
	}
	cout<<ans;
    return 0;
}
