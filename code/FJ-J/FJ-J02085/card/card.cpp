#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn],nxt[maxn];
int lst[maxn];
int ans[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(nxt,-1,sizeof(nxt));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nxt[lst[a[i]]]=i;
		lst[a[i]]=i;
	}
	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;){
			if(nxt[i]==-1) ans[a[i]]++,i++;
			else i=nxt[i];
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
