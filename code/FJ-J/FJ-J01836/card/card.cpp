#include<bits/stdc++.h>
using namespace std;
int n,m,p[300010];
long long f[500010],g[500010],h[300010];
struct node{
	int x,nxt;
}a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		f[i]=i;
		a[p[a[i].x]].nxt=i;
		p[a[i].x]=i;
	}
	for(int i=1;i<=n;i++){
		g[i]+=g[i-1];
		if(a[i].nxt){
			g[a[i].nxt]-=(i-g[i]);
			g[i]+=(i-g[i]);
		}
		f[i]-=g[i];
	}
	for(int i=1;i<=n;i++){
		h[a[i].x]=max(h[a[i].x],f[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<h[i]<<" ";
	}
	return 0;
}