#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

const int N=500005;

int n,m;
int a[N];
int lst[N];
int nxt[N];
int vis[N];
ll ans[N];
void solve(){
	for(int i=n;i>=1;i--){
		if(a[i]!=a[i+1]){
			ans[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	bool flagA=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++){
		flagA&=(a[i]>=a[i-1]);
	}
	if(flagA){
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++){
		nxt[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)vis[j]=0;
		for(int j=1;j<=m;j++)lst[j]=0;
		for(int j=i;j<=n;j++){
			nxt[j]=lst[a[j]];
			lst[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(vis[j])continue;
			if(!nxt[j])continue;
			if(vis[nxt[j]])continue;
			for(int k=nxt[j];k<j;k++)vis[k]=1;
		}
		
		for(int j=i;j<=n;j++){
			if(vis[j])continue;
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	//zhetizhengeidalijiele
	//yihanshouchang
	//buzhidaoshanandu
	//chulaiyaoshihuangjiuzhinengtuiyile
	return 0;
}
