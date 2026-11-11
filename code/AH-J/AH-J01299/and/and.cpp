#include<bits/stdc++.h>
using namespace std;

long long ans=-1,q,n,m,a[2000010],mx=-1;
void dfs(int xb,long long ans1,int m1){
	if(xb==n){
		if(m1==m) ans=max(ans,ans1);
		return;
	}
	if(m1>m){
		return;
	}
	dfs(xb+1,ans1&a[xb],m1+1);
	dfs(xb+1,ans1,m1);
}
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	q=a[1];
	if(m==1){
		cout<<mx;
	}else if(m==n){
		for(int i=2;i<=n;i++){
			q&=a[i];
		}
		cout<<q;
	}else{
		for(int i=1;i<=n;i++){
			dfs(i,a[i],0);
		}
		cout<<ans;
	}

    return 0;
}
