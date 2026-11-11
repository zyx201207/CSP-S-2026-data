#include<bits/stdc++.h>
using namespace std;
long long n,m,a[514514],ans=1,sum,mm,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{	cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	if(sum==(a[1]+a[n])*n/2)
	{	for(int i=1;i<=n;i++) 
		{	
			m-=i*(a[i+1]-a[i]);
			if(m<0) break;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++) 
		{	mm=m;
			for(int j=i;j>=1;j--)
			{	mm-=(a[i]-a[j]);
				if(mm<0) break;
				cnt++;
			}
			ans=max(ans,cnt);
			cnt=0;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
