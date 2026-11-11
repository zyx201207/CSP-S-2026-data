#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m;
int a[N];
int last[N];
int lst[N];
bool vis[N];
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(last[a[i]]) lst[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));
		for(int j=n;j>=i;j--){
			vis[a[j]]=true; 
			if(lst[j]>=i) break;
		}
		for(int j=1;j<=m;j++){
			if(vis[j])cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}