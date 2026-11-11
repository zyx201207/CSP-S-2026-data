#include<bits/stdc++.h>
using namespace std;
int n,m,ma,cnt,ans,a[200005];
void dfs(int k,int sum,int num){
	if(k==n+1){
		if(num==m){
			ans=max(ans,sum);
		}
		return;
	}
	dfs(k+1,sum,num);
	int s=sum;
	if(sum==-1)sum=a[k];
	else sum&=a[k];
	dfs(k+1,sum,num+1);
	sum=s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		if(i==1)cnt=a[i];
		else cnt&=a[i];
	}
	if(n==m){
		cout<<cnt<<'\n';
		return 0;
	}
	if(m==1){
		cout<<ma<<'\n';
		return 0;
	}
	ma=-1;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma<<'\n';
		return 0;
	}
	if(n<=20){
		dfs(1,-1,0);
		cout<<ans<<'\n';
		return 0;
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--)ans&=a[i];
	cout<<ans<<'\n';
	return 0;
}
