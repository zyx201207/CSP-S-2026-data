#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n,m,num,k;
long long a[N];
char s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	for(int l=1,r=n;l<r;)
	{
		if(a[l]>a[r])
		{
			if(s[l]!=s[r])
			{
				num+=a[r];
			}
			a[l]-=a[r];r--;
		}
		else if(a[l]<a[r])
		{
			if(s[l]!=s[r])
			{
				num+=a[l];
			}
			a[r]-=a[l];l++;
		}
		else
		{
			if(s[l]!=s[r]) num+=a[l];
			l++;r--;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
