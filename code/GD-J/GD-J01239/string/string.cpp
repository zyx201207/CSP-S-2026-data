#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l,r,ans;
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
	}
	l=1,r=n;
	while(l<r)
	{
		if(a[l]>a[r])
		{
			if(ch[l]!=ch[r])ans=ans+a[r],a[l]=a[l]-a[r];
			r--;
		}
		else
		{
			if(ch[l]!=ch[r])ans=ans+a[l],a[r]=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
} 
