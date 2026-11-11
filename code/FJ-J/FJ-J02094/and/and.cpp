#include<bits/stdc++.h>
using namespace std;
int n,m;
long long maxa,ans,maxpow=1,a[200010];
void dfs(int x,int cnt,long long mihoyo){
	if(cnt==m){
		ans=max(ans,mihoyo);
		return;
	}
	if(x>n)
		return;
	for(int i=0;i<=1;i++){
		if(i==1)
			dfs(x+1,cnt+1,mihoyo&a[x]);
		else
			dfs(x+1,cnt,mihoyo);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=30;i++)
		maxpow*=2;
	cin>>n>>m;
	long long sum=maxpow-1;
	long long mina=maxpow;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
		mina=min(mina,a[i]);
		sum&=a[i];
	}
	if(n<=20)
		dfs(1,0,maxpow-1);
	else if(m==1)
		ans=maxa;
	else if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(a[i]&a[j],ans);
	}
	else if(m==n)
		ans=sum;
	else{
		sort(a+1,a+n+1);
		ans=a[n-m+1];
	}
	cout<<ans<<endl;
	return 0;
}
