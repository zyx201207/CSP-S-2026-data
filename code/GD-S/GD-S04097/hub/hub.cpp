#include<bits/stdc++.h>
using namespace std;
int b[5000010],c,ttt,n,k,a[5000010];
int zz(int ans){
	if(b[ans]!=ans){
		b[ans]=zz(b[ans]);
		return b[ans];
	}
	return b[ans];
}
void check(int u,int v){
	if(zz(b[u])!=zz(b[v])) b[u]=b[v];
	return;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>ttt;
	for(int i=1; i<=ttt; i++) {
		cin>>n>>k;
		memset(b,0,sizeof(false));
		memset(a,0,sizeof(false));
		int u,v;
		if(n==k) {
			for(int i=1; i<=n-1; i++) {
				cin>>u>>v;
			}
			cout<<1<<endl;
		} else {
			for(int i=1; i<=n-1; i++) b[i]=i;
			for(int i=1; i<=n-1; i++) {
				int u,v;
				cin>>u>>v;
				check(u,v);
			}
			int p=1;
			a[1]=zz(1);
			for(int i=2;i<=n;i++){
				for(int i=1;i<=p;i++){
					if(a[i]!=zz(i)){
						 a[p++]=zz(i);
					}
				}
			}
			cout<<p;
		}
	}
	return 0;
}
