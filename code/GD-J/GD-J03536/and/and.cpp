#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005],ans=-1,ans5a[200005],ans6a[5];
void dfs(int v,int cnt,int temp){
	if(cnt>=m){
		//cout<<ans<<endl;
		ans=max(ans,temp);
		return ; 
	}
	for(int i=v+1;i<=n+cnt-m+1;i++){
		dfs(i,cnt+1,temp&a[i]);
	}
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxa=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
	}
	if(n<=20){
		for(int i=1;i<=n-m;i++){
			dfs(i,1,a[i]);
		}
		cout<<ans;
	}
	else if(m==1) cout<<maxa;
	else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}
	else if(m==1){
		int ans4=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans4=max(ans4,a[i]&a[j]);
			}
		}
		cout<<ans4;
	}
	else{
		cout<<maxa;
	}
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
