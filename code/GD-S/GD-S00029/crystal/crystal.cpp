#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans,sum,s;
int l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}

	int le=0,r=0;
	for(int i=1;l<=n,r<=n;i++)
	{
	
		
		ans=b[r]-sum;
		if(ans<=m)
		{
			l=max(l,r-le);
			//cout<<le<<" "<<r<<endl;
			r++;
		sum+=le*(a[r]-a[r-1]);
		}
		else
		{
		le++;	sum+=a[r]-a[le];
		}
		
	}
	cout<<l;
	return 0;
} 
