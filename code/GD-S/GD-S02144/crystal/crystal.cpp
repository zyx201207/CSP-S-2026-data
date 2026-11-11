#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+50;
ll n,m,sum,ans,maxn;
ll a[N];
ll s[N];//,s1[N];
bool vis[N];
bool ok,okk;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0); 
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		//3sum+=a[i];
		if(a[i]!=i) ok=1;
    }
    sort(a+1,a+n+1);
    int k=a[2]-a[1];
    for(int i=2;i<=n;i++)
    {
    	if(a[i]-a[i-1]!=k) okk=1;
	}
	if(ok==0)
	{
		cout<<min(m+1,n);
		return 0;
	}
	if(okk==0)
	{
		cout<<min(n,m/k+1);
		return 0;
	}
	//s1[1]=a[1];
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+abs(a[n]-a[i]);
	}
	//cout<<s[n];
	if(m>=s[n]*2)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int j=i,sum=0;
		ll ans1=0,ans2=0;
		while(sum<=m&&j<=n)
		{
		    j++;
			sum=sum+abs(a[j]-a[i]);			
			ans1++;
			//cout<<sum<<" "<<ans1<<endl;
		} 
		sum=0;
		int k=j;
		while(sum<=m&&j>=1)
		{
		    j--;
			sum=sum+abs(a[k]-a[j]);			
			ans2++;
			//cout<<sum<<" "<<ans2<<endl;
		}
		ans1=max(ans1,ans2);
		ans=max(ans,ans1);
	}
	cout<<min(n,ans);
	return 0;
} 
