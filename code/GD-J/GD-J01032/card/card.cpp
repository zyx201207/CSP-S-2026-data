#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5,K=5e3+5;
int n,m;
int a[N];
int lst[M];
int nxt[N];
int ans[M];
int mx[N];
int sf[N];
bool bz[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int j=n;j>=1;j--){
		nxt[j]=lst[a[j]];
		if(nxt[j]==0)nxt[j]=j+1;
		if(lst[a[j]]==0)lst[a[j]]=j;
	}
	bool ssf=1;
	for(int i=1;i<=n;i++) if(a[i-1]>a[i])ssf=0;
	if(ssf){
		for(int i=n,j;i>=1;i=j){
			j=i;
			while(j>=1&&a[j]==a[i])j--;
			ans[a[i]]=i;
		}
		for(int t=1;t<=m;t++)cout<<ans[t]<<" ";
		return 0;
	}
//	for(int i=1;i<=n;i++)sf[i+1]++,sf[nxt[i]]--,mx[i]=max(mx[i-1],nxt[i]);
//	for(int i=1;i<=n;i++)sf[i]+=sf[i-1],cout<<sf[i]<<" ";cout<<"\n";
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j=nxt[j]){
			if(!bz[a[j]])ans[a[j]]++;
			bz[a[j]]=1;
		}
		for(int j=i;j<=n;j=nxt[j])bz[a[j]]=0;
	}
	for(int t=1;t<=m;t++)cout<<ans[t]<<" ";
	return 0;
}/*
10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 2 1 3
*/
