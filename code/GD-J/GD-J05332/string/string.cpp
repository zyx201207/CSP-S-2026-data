#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans;
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1,j=n;i<=j;)
	{
		if(a[i]<a[j])
		{
			if(b[i]!=b[j])ans+=a[i];
			a[j]-=a[i],i++;
		}
		else 
		{
			if(b[i]!=b[j])ans+=a[j];
			a[i]-=a[j],j--;
		}
	}
	cout<<ans;
	return 0;
} 
