#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,sum;
int a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i],sum+=a[i];
	for(int i=1,j=n;i<j;)
	{
		while(a[i]>=a[j])
		{
			if(s[i]!=s[j]) ans+=a[j];
			a[i]-=a[j],a[j]=0,j--;
		}
		if(a[i]==0) i++;
		while(a[j]>=a[i])
		{
			if(s[i]!=s[j]) ans+=a[i];
			a[j]-=a[i],a[i]=0,i++;
		}
		if(a[j]==0) j--;
	}
	cout<<ans;
	return 0;
}
