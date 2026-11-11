#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,l=0,r,ans=0;
	char x;
	cin>>n;
	r=n;
	int a[n+1],b[n+1];
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>x;
		b[i]=x-'a'+1;
		a[i]+=a[i-1];
	}
	for(int i=1;i<=a[n]/2;i++)
	{
		if(i>a[l])l++;
		if(i>a[n]-a[r-1])r--;
		if(b[l]!=b[r])ans++;
	}
	cout<<ans;
    return 0;
}
