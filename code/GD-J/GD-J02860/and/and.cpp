#include<bits/stdc++.h>
using namespace std;
#define t long long
t a[2000005],f[2000005],dp[1000001],n,m,ans,s;
int cmp(int a,int b){
	return a>b; 
}
void o(){
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==0)k++;
	}if (k>=2)cout<<0,exit(0);
	if (k==1){
		ans=a[1];
		for(int i=2;i<=n;i++){
			if (a[i]!=0)ans&=a[i];
		}
		cout<<ans,exit(0);
	}else{
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}
	cout<<ans&1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if (m==n-1){
		o();
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)f[i]=0,dp[i]=0;
		dp[1]=a[k];
		f[k]=1;
		for(int i=2;i<=m;i++){
			for(int j=1;j<=n;j++){
				if (a[j]!=0&&f[j]==0){
					if (dp[i]<dp[i-1]&a[j])dp[i]=dp[i-1]&a[j],s=j;
				}
			}f[s]=1;
		}
		ans=max(ans,dp[m]);
	}cout<<ans;
	return 0;
}
