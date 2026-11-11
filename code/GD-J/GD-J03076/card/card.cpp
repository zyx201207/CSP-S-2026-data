#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int n,m;
int ans[N];
bool vis[N];
int st[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int top=0;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				top++;
				st[top]=j;
			}else{
				while(top>0&&a[st[top]]!=a[j]){
					vis[a[st[top]]]=0; top--;
				}
				st[top]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
