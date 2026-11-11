#include<bits/stdc++.h>
using namespace std;
long long n,t[200005],ans;
string s;
char a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i]>>a[i];
	long long l=1,r=n;
	while(l<=r)
	{
		if(a[l]==a[r])
		{
			if(t[l]>t[r]) t[l]-=t[r],r--;
			else if(t[r]>t[l]) t[r]-=t[l],l++;
			else l++,r--;
		}
		else
		{
			if(t[l]>t[r]) ans+=t[r],t[l]-=t[r],r--;
			else if(t[r]>t[l]) ans+=t[l],t[r]-=t[l],l++;
			else ans+=t[l],l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
