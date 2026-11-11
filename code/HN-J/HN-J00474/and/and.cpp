#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int f;
int a[200000+10]={};
int mx=0;
void dfs(int s,int b,int x){
	if(b>m||x<ans||m-b>n-s+1) return ;
	if(s==n+1){
		if(b==m)ans=max(ans,x);
		return ;
	}
	dfs(s+1,b,x);
	dfs(s+1,b+1,x&a[s]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(a[i]!=i-1){
			f=1;
		}
	}if(!f){
		cout<<n-m;
		return 0;
	}if(mx>=4&&n>2000){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}if(mx<4&&n>2000){
		int sum[4]={};
		for(int i=1;i<=n;i++) sum[a[i]]++;
		if(sum[3]>=m){
			cout<<3;
		}else if(sum[2]+sum[3]>=m){
			cout<<2;
		}else if(sum[3]+sum[1]>=m){
			cout<<1;
		}else{
			cout<<0;
		}return 0;
	}
	dfs(1,0,((2<<30)-1));
	cout<<ans;
	return 0;
}
