#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200000+10],m,ma,s[200000+10];
void dfs(int u,int v){
	if(v==m+1){
		int sum,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]){
				sum=a[i];

			}
		}
		for(int i=1;i<=n;i++){
			if(s[i]){
				sum=a[i]&sum;
			}
		}
		ma=max(ma,sum);
		return ;
	}
	if(u==n+1)return ;
	s[u]=1;
	dfs(u+1,v+1);
	s[u]=0;
	dfs(u+1,v);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	if(n<=20){
		dfs(1,1);
		cout<<ma;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma; 
	}
}
