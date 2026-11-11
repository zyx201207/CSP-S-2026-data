#include<bits/stdc++.h>
#define inf ((1<<21)-1)
using namespace std;
int n,m,a[200010],s,mx,ans,res,v[200010];
bool fb=1;
void dfs(int p,int ss){
	if(p==m){
		ans=max(ans,ss);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			dfs(p+1,ss&a[i]);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)fb=0;
		mx=max(mx,a[i]);
		if(i==1)s=a[i];
		else s&=a[i];
	}
	if(m==1){
		cout <<mx;
		return 0;
	}else if(m==n){
		cout <<s;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				res=max(res,a[i]&a[j]);
			}
		}
		cout <<res;
		return 0;
	}else if(fb){
		res=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			res&=a[i];
		}
		cout <<res;
		return 0;
	}else if(n<=20){
		dfs(0,inf);
		cout <<ans;
	}else{
		;
	}
	return 0;
}
