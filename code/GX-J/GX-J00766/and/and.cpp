#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long nx=-1,n,m;
void dfs(int cnt,long long x,int k){
	if(cnt==m){
	    nx=max(nx,x);
	    return ;
	}
	if(k==n+1)
	    return ;
	if(x==0&&cnt==0) dfs(cnt+1,a[k],k+1);
	else dfs(cnt+1,x&a[k],k+1);
	dfs(cnt,x,k+1);
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		long long mx=-1;
		for(int i=1;i<=n;i++)
		    mx=max(a[i],mx);
		cout<<mx;
		return 0;
	}
	if(m==2){
		long long mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				mx=max(a[i]&a[j],mx);
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(0,0,0);
		cout<<nx;
		return 0;
	}
	return 0;
}
