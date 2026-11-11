#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> c[33];
int cnt[200005][33]={};
int a[200005];
int max1=0;
int vis[200005];
void add(int x,int i){
	int cnt1=0;
	while(x!=0){
		if(x%2){
			cnt[i][cnt1]++;
			c[cnt1].push_back(a[i]);
		}
		x/=2;
		cnt1++;
	}
	return;
}
void dfs(int i,int m,int cnt1,int an){
	if(cnt1==m){
		max1=max(max1,an);
		return;
	}
	for(int j=0;j<c[i].size();j++){
		if(vis[j]){
			continue;
		}else{
			vis[j]=1;
			dfs(i,m,cnt1+1,an&c[i][j]);
			vis[j]=0;
		}
	}
	return;
} 
int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		add(a[i],i);
	}
	int flag=0;
	int ans=0;
	for(int i=32;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			sum+=cnt[j][i];
		}
		if(sum>=m){
			dfs(i,m,0ll,2147483647ll);
			break;
		}
	}
	cout<<max1;
	return 0;
}

