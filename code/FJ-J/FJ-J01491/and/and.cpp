#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],t[32],ans=-1;
bool A=1;
bool vis[200005];
void dfs(int i,int s){
	if(s==m){
		long long q=pow(2,40)-1;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				q&=a[i];
			}
		}
		ans=max(ans,q);
	}
	if(i>n){
		return;
	}
	vis[i]=1;
	dfs(i+1,s+1);
	vis[i]=0;
	dfs(i+1,s);
}
int main(){
	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
 	t[0]=1;
 	for(int i=1;i<=31;i++){
 		t[i]=t[i-1]<<1;
	}
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		if(A==1){
 			int f=0;
 			for(int j=1;j<=31;j++){
 				if(a[i]==(t[j]-1)){
 					f=1;
 					break;
				 }
			}
			if(f==0){
				A=0;
			}
		}
	}
	if(A==1){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(n<=20){
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	else if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}else if(m==n){
		long long q=pow(2,40)-1;
		for(int i=1;i<=n;i++){
			q&=a[i];
		}
		cout<<q;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<1;
 	return 0;
}
