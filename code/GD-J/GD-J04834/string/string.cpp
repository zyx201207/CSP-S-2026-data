#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

const int N=2e5;

int n;
int a[N+2]; char c[N+2];

long long sum[N+2];
long long ans;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],sum[i]=sum[i-1]+a[i];
	
	long long mid=0;
	if(sum[n]&1)
	{
		long long k=sum[n]/2+1;
		int pos=lower_bound(sum+1,sum+1+n,k)-sum;
		
		if(a[pos]<=2)
		{
			if(a[pos]==1)
			{
				for(int i=pos;i<n;i++) a[i]=a[i+1],c[i]=c[i+1];
				n--;
			}
			else a[pos]--;
			mid=pos-1;
		}
		else
		{
			a[pos]--;
			if(sum[pos]!=k)
			{
				for(int i=n;i>=pos+1;i--) a[i+1]=a[i],c[i+1]=c[i];
				n++;
				
				k--;
				a[pos+1]=a[pos]-(k-sum[pos-1]),c[pos+1]=c[pos];
				a[pos]=k-sum[pos-1];
			}
			mid=pos;
		}
//		for(int i=1;i<=n;i++) cout<<a[i]<<c[i]<<' ';
	}
	else
	{
		long long k=sum[n]/2;
		int pos=lower_bound(sum+1,sum+1+n,k)-sum;
		if(sum[pos]!=k)
		{
			for(int i=n;i>=pos+1;i--) a[i+1]=a[i],c[i+1]=c[i];
			n++;
			
			a[pos+1]=a[pos]-(k-sum[pos-1]),c[pos+1]=c[pos];
			a[pos]=k-sum[pos-1];
		}
		mid=pos;
//		for(int i=1;i<=n;i++) cout<<a[i]<<c[i]<<' ';
	}
//	cout<<mid<<"%\n";
	int l=0; long long cntl=0;
	for(int r=n;r>=mid+1;r--)
	{
		long long sum=0; cntl=0;
		while(l<mid&&cntl<a[r])
		{
			cntl+=a[++l];
			if(cntl>=a[r])
			{
				cntl-=a[l];
				break;
			}
			if(c[l]!=c[r]) sum+=a[l];
			//cout<<l<<'#'<<a[l]<<'\n';
		}
		ans+=sum;
		
		//cout<<cntl<<' '<<a[r]<<'\n';
		if(cntl<=a[r])
		{
			if(c[l]!=c[r]) ans+=a[r]-cntl;
			int k=a[r]-cntl; a[l--]-=k;
		}
		//cout<<ans<<'\n';
	}
	
	cout<<ans;
	
	return 0;
}
/*
6
2 a
1 b
1 c
1 b
2 a
1 b
*/
