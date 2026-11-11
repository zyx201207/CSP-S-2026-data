#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int vis[N]; 
int n,m;
int ans;
int a[N];
int d[N];
void dfs(int cnt,int sum){
	if(cnt>m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){			
			vis[i]=1;
			if(cnt==1){
				dfs(cnt+1,(a[i]));
			}
			else{
				dfs(cnt+1,(sum&a[i]));
			}
			vis[i]=0;
		}
	}
	
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];						
	}
	if(m==1){
		ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);	
		} 
		
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		} 
		
	}
	else if(m==2){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		
	}	
	else{
		dfs(1,0);
	}
	cout<<ans;
} 
/*
4 2
3 15 12 12

5 3
31 3 1 15 7








*/
