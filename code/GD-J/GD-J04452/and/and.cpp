#include<bits/stdc++.h>
using namespace std;
int n,m,maxx;
int a[10000000];
int b[10000000];
void dfs(int x,int ans){
	if(x==m+1){
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			dfs(x+1,ans&a[i]);
			b[i]=0;
		}
	}
	
}
int main(){//突然发现打表最多能得75分 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
	}
	if(m==1){
		cout<<maxa;
		return 0;
	}
	if(m==2){
		maxa=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				maxa=max(maxa,a[i]&a[j]);
		cout<<maxa;
		return 0;
	}
	if(m==n){
		int ans=0b111111111111111111111;
		for(int i=1;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(1,0b111111111111111111111);
		cout<<maxx;
		return 0;
	} 
	sort(a+1,a+1+n);
	int i=n,ans=0b111111111111111111111;
	while(m--){
		ans&=a[i];
		i--;
	}
	cout<<ans;
	return 0;
}

