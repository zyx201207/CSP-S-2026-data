#include<bits/stdc++.h>
using namespace std;
int n,m,b[5];
long long ans,a[100005];
bool vis[100005];
void dfs(int x,long long s){
	if(x==m){
		ans=max(ans,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(x==0){
				dfs(x+1,a[i]);
			}else{
				dfs(x+1,s&a[i]);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4){
			f=false;
		}
	}
	if(n<=20){
		dfs(0,0);
	}else if(f){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		if(b[4]>=m){
			ans=4;
		}else if(b[3]>=m){
			ans=3;
		}else if(b[2]>=m||b[3]+b[2]>=m){
			ans=2;
		}else if(b[1]>=m||b[3]+b[1]>=m){
			ans=1;
		}
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
/*
5 3
31 3 1 15 7
4 2
3 15 12 12
*/
