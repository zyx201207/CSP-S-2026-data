#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,ans=-1,st[200005];
void dfs(int x,int sum,int sta){
	if(x==m+1){
		ans=max(ans,sum);
		return ;
	}
	for(int i=sta+1;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			if(x==1)
			 dfs(2,a[i],1);
			else
			 dfs(x+1,a[i]&sum,i);
			st[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int fl=0,mm=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mm=max(mm,a[i]);
	}
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++)
		 maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;
	}
	if(m==2){
		int maxn=0;
		for(int i=1;i<n;i++)
		 for(int j=1+i;j<=n;j++)
		  maxn=max(maxn,a[i]&a[j]);
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++)
		 sum=sum&a[i];
		cout<<sum;
		return 0;
	}
	if(mm<=4){
		for(int i=1;i<=n;i++)
		 st[a[i]]++;
		if(st[4]>=m)
		 cout<<4;
		else if(st[3]>=m)
		 cout<<3;
		else if(st[3]+st[2]>=m)
		 cout<<2;
		else if(st[1]+st[3]>=m)
		 cout<<1;
		else
		 cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int t=a[i]+1;
		while(t%2==0)
		{
			t/=2;
		}
		if(t!=1){
			fl=1;
			break;
		}
	}
	if(fl==0){
		sort(a+1,a+n+1);
		int sum=a[n];
		for(int i=n-1;i>=n-m+1;i--)
		 sum&=a[i];
		cout<<sum;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
