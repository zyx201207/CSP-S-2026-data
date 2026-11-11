#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int suf[N],sum[N];
int res=0;
inline void dfs(int k,int s,int lst){
	if(n-lst+1+k<m)return;
	if(k==m){
		res=max(res,s);
		return;
	}
	for(int i=lst;i<=n;i++){
		if(k==0)dfs(k+1,a[i],i+1);
		else dfs(k+1,s&a[i],i+1);
		dfs(k,s,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans<<endl;
	}
	else if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans<<endl;
	}
	else if(m==n-1){
		sum[1]=a[1];
		suf[n]=a[n];
		for(int i=2;i<=n;i++)sum[i]=a[i]&sum[i-1];
		for(int i=n-1;i>=1;i--)suf[i]=a[i]&suf[i+1];
		int ans=max(suf[2],sum[n-1]);
		for(int i=2;i<n;i++){
			ans=max(ans,suf[i+1]&sum[i-1]);
		}
		cout<<ans<<endl;
	}
	else if(m==2){
		int ans,op=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(op==0){
					ans=a[i]&a[j];
					op=1;
				}
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans<<endl;
	}
	else if(n>20){
		sort(a+1,a+n+1);
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;i++)ans=ans&a[i];
		cout<<ans<<endl;
	}
	else{
		dfs(0,0,1);
		cout<<res<<endl;
	}
}
