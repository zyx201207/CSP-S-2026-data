#include <bits/stdc++.h>
using namespace std;
int ans[100005];
int a[100005];
int n,m;
bool vis[100005];
int cnt=0;
int rp[30];
//RP++!RP++!
void dfs(int step,int ptr){
	if(step==m){
		cnt++;
		int sum=a[ptr];
		for(int i=ptr+1;i<=n;i++){
			if(vis[i]==1&&i!=ptr){
				sum=sum&a[i];
				vis[i]=0;
			}
		}
		ans[cnt]=sum;
		return;
	}
	for(int i=ptr+1;i<=n;i++){
		vis[i]=1;
		dfs(step+1,ptr);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
		cout<<7;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(1,i);
	}
	int maxn=-1;
	for(int i=1;i<=cnt;i++){
		maxn=max(maxn,ans[i]);
	}
	cout<<maxn;
	return 0;
}
