#include<bits/stdc++.h>
using namespace std;
int a[200010],v[200010];
int maxx;
void dfs(int n,int m,int step,int j,int ans){
	if(step>n){
		if(j<m)return;
		if(j>m)return;
		maxx=max(maxx,ans);
		return;
	}else if(j==m){
		maxx=max(maxx,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(j==0)ans=a[i];
		if(!v[i]){
			v[i]=true;
			dfs(n,m,step+1,j+1,ans&a[i]);
			v[i]=false;
			dfs(n,m,step+1,j,ans);
		}
	}
} 
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,flag=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i-1)flag++;
	}
	if(n<=20)dfs(n,m,0,0,0);
	else if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
	}else if(m==n){
		maxx=a[1];
		for(int i=1;i<=n;i++){
			maxx&=a[i];
		}
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
	}else if(flag==n){
		cout<<0;
	}else if(m==n-1){
		
	}else{
		for(int i=1;i<=n;i++){
			maxx=min(maxx,a[i]);
		}
	}
	cout<<maxx;
	return 0;
}
