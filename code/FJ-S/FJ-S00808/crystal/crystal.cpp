#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,tmp,ans;
long long m,a[N];
bool check(int x,int g)
{
    return (a[g]-a[g-1])*x-(a[g-1]-a[g-x-1])<=m;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+1+n); 
	for(int i=1;i<=n;i++)
	    a[i]+=a[i-1];
	for(int i=1;i<=n;i++)
	{ 
	    int l=1,r=i-1,tmp=0;
	    while(l<=r)
	    {
	        int mid=(l+r)/2;
	        if(check(mid,i))
	        {
	            tmp=mid;
	            l=mid+1;
			}
		    else
		        r=mid-1;
		}
	    ans=max(ans,tmp+1);
	}
	cout<<ans<<endl;
	return 0;
}
	
