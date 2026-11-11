#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
long long sum[500005];
bool b[500005];
void check(int k,int now){
	for(int i=k;i<now;i++){
		if(a[i]==a[now]&&!b[i]){
			for(int j=i+1;j<=now;j++) b[j]=1;
			return;
		}
	}
	return;
}
void dfs(int cnt){
	for(int i=cnt;i<=n;i++){
		check(cnt,i);
	}
	for(int i=cnt;i<=n;i++){
		if(!b[i]) sum[a[i]]++;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		dfs(i);
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
