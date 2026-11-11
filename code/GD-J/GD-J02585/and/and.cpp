#include<bits/stdc++.h>
using namespace std;
const int K=1e5+91;
int n,m;
int a[K];
int maxx=INT_MIN;
int ans=0;
void dfs(int x,int cnt){
	if(x>n||cnt==m){
		maxx=max(maxx,ans);
		return ;
	}
	dfs(x+1,cnt);
	if(ans==0){
		ans=a[x];
	}else{
		ans=ans&a[x];
	}
	dfs(x+1,cnt+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1,0);
		cout<<maxx<<endl;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxx=max(a[i],maxx);
		}
		cout<<maxx<<endl;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n>2000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=a[n];
		int i=n;
		for(int j=1;j<=m;j++){
			ans=ans&a[i];
			cout<<a[i]<<' '<<endl;
			i-=2;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx<<endl;
		return 0;
	}
	
	
	
	
	return 0;
}
