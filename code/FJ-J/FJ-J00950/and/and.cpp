#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=235299;
int a[N],b[N];
char c[N];
int pre[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	pre[0]=1;
	int ans=0;
	for(int i=1;i<=19;i++){
		pre[i]=pre[i-1]*2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=18;j++){
			if(a[i]>=pre[j]&&a[i]<pre[j+1]){
				b[i]=j;
			} 
		}
	}
	sort(a+1,a+n+1);
		for(int i=n;i>=1;i--)
	    {
	    	int cnt=1;
		    for(int j=1;j<=n-1;j++){
			   if(a[j]==a[i])cnt++;
		    }
		    if(cnt>1&&cnt<m)
		    ans=max(ans,a[i]);
			else if(cnt>=m){
				ans=a[i];
				break;
			} 
	    }
	    cout<<ans;
	return 0;
}
