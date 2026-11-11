#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
	}
	int left=1,right=n;
	long long al=0,alr=0;
	long long ans=0;
	while(left<right)
	{
		int l=a[right];
		int r=a[left];
		if(c[left]!=c[right])
		{
			ans+=min(l-al,r-alr);
		}
		al+=min(l-al,r-alr);
		alr+=min(l-al,r-alr);
		if(al>alr)
		{
			right--;
		}
		else if(al<alr)
		{
			left++;
		}
		else
		{
			right--;
			left++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
