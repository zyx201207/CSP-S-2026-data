#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxn=0,ans=0,cnt=1,a[200001];
signed main() {
//    freopen("and.in","r",stdin);
//    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
		ans=a[1];
    if(n==m)
    {
    	
    	for(int i=1;i<=n;i++)
    	    ans=(ans&a[i]);
    	cout<<ans;
    	return 0;
	}
	if(m==2)
	{
    	for(int j=cnt;j<n;j++)
    	{
    		for(int k=j+1;k<=n;k++)
    			ans=max(ans,a[j]&a[j]);
    	} 
    	cout<<ans;
    	return 0;
	}
	if(m==3)
	{
    	for(int j=cnt;j<n;j++)
    	{
    		for(int k=j+1;k<=n;k++)
    			for(int l=k+1;l<=n;l++)
    				ans=max(ans,a[k]&a[j]&a[l]);
    	} 
    	cout<<ans;
    	return 0;		
	}
	return 0;
}

