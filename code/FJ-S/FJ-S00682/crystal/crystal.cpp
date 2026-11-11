#include<iostream>
#include<algorithm>
using namespace std;
const int N=5*1e5+1;
long long n,m,a[N],b[N],dp[N],ans=1,temp=0;
int check4(long long t,long long qi){
	long long x=0,j=t-1,ans1=1;
	while(j>=1&&x<=m){
		if(a[t]-a[j]+x<=m){
			x+=a[t]-a[j];
			j--;
			ans1++;
		}else{
			break;
		}
	}
	ans=max(ans,ans1);
	if(ans1<t-qi+1){
		return 0;
	}
	else
	return 1;
}
int check3(long long t,long long qi){
	long long x=0,j=t-1,ans1=1;
	while(j>=1&&x<=m){
		if(a[t]-a[j]+x<=m){
			x+=a[t]-a[j];
			j--;
			ans1++;
		}else{
			break;
		}
	}
	ans=max(ans,ans1);
	if(ans1<t-qi+1){
		long long l=t,r=n;
		while(l<=r){
			long long mid=(l+r)/2;
			if(check4(mid,l))
			l=mid+1;
			else
			r=mid-1;
		}
		return 0;
	}
	else
	return 1;
}
int check2(long long t,long long qi){
	long long x=0,j=t-1,ans1=1;
	while(j>=1&&x<=m){
		if(a[t]-a[j]+x<=m){
			x+=a[t]-a[j];
			j--;
			ans1++;
		}else{
			break;
		}
	}
	ans=max(ans,ans1);
	if(ans1<t-qi+1){
		long long l=t,r=n;
		while(l<=r){
			long long mid=(l+r)/2;
			if(check2(mid,l))
			l=mid+1;
			else
			r=mid-1;
		}
		return 0;
	}
	else
	return 1;
}
int check1(long long t,long long qi){
	long long x=0,j=t-1,ans1=1;
	while(j>=1&&x<=m){
		if(a[t]-a[j]+x<=m){
			x+=a[t]-a[j];
			j--;
			ans1++;
		}else{
			break;
		}
	}
	ans=max(ans,ans1);
	if(ans1<t-qi+1){
		long long l=t,r=n;
		while(l<=r){
			long long mid=(l+r)/2;
			if(check2(mid,l))
			l=mid+1;
			else
			r=mid-1;
		}
		return 0;
	}
	else
	return 1;
}
bool check(long long t){
	long long x=0,j=t-1,ans1=1;
	while(j>=1&&x<=m){
		if(a[t]-a[j]+x<=m){
			x+=a[t]-a[j];
			j--;
			ans1++;
		}else{
			break;
		}
	}
	ans=max(ans,ans1);
	if(ans1<t)
	{
		long long l=t,r=n;
		while(l<=r){
			long long mid=(l+r)/2;
			if(check1(mid,l))
			l=mid+1;
			else
			r=mid-1;
		}
		return 0;
	}
	else
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int j=0;j<=m;j++)
	dp[j]=1;
	for(int i=1;i<n;i++)
	b[i]=(a[i+1]-a[i])*i+b[i-1];
	if(n<=16){
		for(int i=2;i<=n;i++)
		{
			for(int j=m;j>=0;j--){
				int k=b[i-1]-b[i-2];
				if(k<=m)
				dp[j]=max(dp[j],dp[j-k]+1);
			}
		}
		cout<<dp[m];
		return 0;
	}
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid))
		l=mid+1;
		else
		r=mid-1;
	}
	cout<<ans;
	return 0;
}
//1000000000000
//314780

