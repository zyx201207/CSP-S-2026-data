#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char s[N];
string nn;
int n;
int ans=0;
int l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int k=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		r+=a[i];
		for(int j=1;j<=a[i];j++ )
		{
			nn[k]=s[i];
			k++;
		}
	}
	
	while(l<r)
	{
		int mid=1+(l+r)/2;
		if(nn[l]==nn[r])
		{
			l++;
			r++;
		}else
		{
			ans++;
			l++;
			r++;
		}
		
	}
	cout<<ans;
	return 0;
}

