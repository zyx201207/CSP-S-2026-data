#include<bits/stdc++.h> 
using namespace std;
int n,a[200005];
char s[200005];
long long ans;
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>s[i];
	}
	for(int i=1,j=n;i<=j;)
	{
		if(s[i]!=s[j]) 
		{
			if(a[i]>a[j]) ans=ans+a[j],a[i]=a[i]-a[j],j--;
			else ans=ans+a[i],a[j]=a[j]-a[i],i++;			
		}
		else i++;
	}
	printf("%lld",ans);
	return 0;
}
