#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],to[N],nw[M],in[N],d[N],q[N],hh,tt,ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		if(nw[a[i]])to[i]=nw[a[i]],in[nw[a[i]]]++;
		else to[i]=i+1,in[i+1]++;
		nw[a[i]]=i;
		d[i]=1;
	}
	tt=-1;
	for(int i=1;i<=n;i++)if(!in[i])q[++tt]=i;
	while(hh<=tt){
		int u=q[hh++];
		if(u>n)continue;
		int v=to[u];
		in[v]--;
		if(!in[v])q[++tt]=v;
		d[v]+=d[u];
	}
	memset(nw,0,sizeof nw);
	for(int i=n;i>=1;i--){
		if(!nw[a[i]])ans[a[i]]=d[i];
		nw[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
} 
/*
10 1
1 1 1 1 1 1 1 1 1 1 

*/
