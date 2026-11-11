#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005],b[200005];
void dfs(int x,int cnt){
	if(x==n+1){
		if(cnt==m){
			int num=a[1];
			for(int i=2;i<=m;i++){
				num=num&a[i]; 
			}
			ans=max(ans,num);
		}
		return ;
	}
	if(cnt<m){
		cnt++;
		a[cnt]=b[x];
		dfs(x+1,cnt);
		a[cnt]=0; 
		cnt--;
		dfs(x+1,cnt);
	}else{
		dfs(n+1,cnt);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	dfs(1,0);
	cout<<ans;	
	return 0;
}

