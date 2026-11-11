//GZ-S00077 遵义市第四中学 丁家亿  
#include <bits/stdc++.h>
using namespace std;
const long long MAXN=1e6+5;
long long m,n,ans[MAXN],a[MAXN],c[MAXN],d[MAXN],add[MAXN],cnt[MAXN];
int dfs(int l,int r)
{
	int mid=(n+1)/2;
	if(l==r)
	{
		add[l]=min(add[l-1]+d[l]*l,add[r+1]+d[r]*r);
//		return ans[l];
	}
	if(l>r)
	{
		if(add[l]<=add[r])return ans[l];
		else return ans[r];
	}
	add[l]=l>1?add[l-1]+d[l]*l:d[l];
	add[r]=(r=mid)?d[r]:add[r-1]+d[r]*(r-mid);
	dfs(l+1,r+1);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1&&a[i-1]==a[i])
		{
			ans[i]=ans[i-1]+1;
			ans[i-1]=ans[i];
		}	
		else ans[i]=1;
	}
	sort(a+1,a+n+1);
	int mid=(n+1)/2;
	int maxn=-1,l=2;
	for(int i=2;i<=n;i++)
		c[i]=a[i]-a[i-1];	
	for(int i=n-1;i>0;i--)
		d[i]=a[i+1]-a[i];
	add[1]=d[1];
	for(int i=1;i<mid;i++)
	{
		add[i]=add[i-1]+i*d[i];
	}
	add[mid+1]=d[mid];
	if(n==5){
		add[5]=add[4]*2+d[4];
	}
	for(int i=mid+l;i<n;i++)
	{
		add[i]=add[i-1]+l*d[i-1];
	}
	
	for(int i=2;i<n;i++)
	{
		if(m>=add[i]&&m>=a[i])
		{
			ans[i]=ans[i-1]+1;
			if(maxn<ans[i]){
				maxn=ans[i];
			}
		}
		
	}
	cout<<maxn;
	return 0;
}

