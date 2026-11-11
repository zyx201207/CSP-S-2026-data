#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,cnt,c;
int a[100005];
int vis[100005];
void dfs(int k){
	if(k>m){
		if(cnt>maxx){
			maxx=cnt;
		}
		return;
	}
	for(int j=1;j<=n;j++){
		if(vis[j]==0){
			c=cnt;
			cnt=cnt&a[j];		
			vis[j]=1;
			dfs(k+1);
			vis[j]=0;
			cnt=c;
		}
	}
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			cnt=a[i];
			//cout<<a[i]<<" ";
			vis[i]=1;
			dfs(2);
		}
		cout<<maxx;
	}
	else{
		if(m==1){
			int hyf=a[1];
			for(int i=2;i<=n;i++){
				if(a[i]>hyf){
					hyf=a[i];
				}
			}
			cout<<hyf;
		}
		else if(m==n){
			int qf=a[1];
			for(int i=2;i<=n;i++){
				qf=qf&a[i];
			}
			cout<<qf;
		}
		else if(m==2){
			int zx=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						zx=max(zx,a[i]&a[j]);
					}
				}
			}
			cout<<zx;
		}
		else{
			int xya=a[1];
			for(int i=2;i<=n;i++){
				if(a[i]<xya){
					xya=a[i];
				}
			}
			cout<<xya;
		}
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/
