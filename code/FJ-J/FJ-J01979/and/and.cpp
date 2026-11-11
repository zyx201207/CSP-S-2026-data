#include<bits/stdc++.h>
using namespace std;
int a[200005],dp[2005][2005],b[200005],n,m,maxx=-1;
void dfs(int k,int l,int ans){
	if(l==m){
		maxx=max(maxx,ans);
		return;
	}
	for(int i=k;i<=n;i++){
		if(l==0)
		dfs(i+1,l+1,a[i]);
		else
		dfs(i+1,l+1,ans&a[i]);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int sum;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)
		sum=a[1];
		else
		sum=sum&a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++)
		maxx=max(maxx,a[i]);
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		cout<<sum;
		return 0;
	}
	else if(n<=20){
		dfs(1,0,0);
	}
	else {
		sort(a+1,a+n+1);
		int cnt=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			cnt&=a[i];
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0; 
} 
