#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char s[200005];
int ans=0;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	for(int i=1,j=n;i<=j;)
	{
		if(i==j)
		break;
		if(s[i]==s[j])
		{
			int mi=min(a[i],a[j]);
			a[i]-=mi;
			a[j]-=mi;
			if(a[i]==0)
			i++;
			if(a[j]==0)
			j--;
		}
		else
		{
			int mi=min(a[i],a[j]);
			a[i]-=mi;
			a[j]-=mi;
			if(a[i]==0)
			i++;
			if(a[j]==0)
			j--;
			
			ans+=mi;
		}
	}
	cout<<ans;
	
	
	return 0;
}
