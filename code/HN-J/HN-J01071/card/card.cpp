#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],t[500005],vis[500005],f[500005];
void solve(int x){
	memset(f,0,sizeof(f));
	memset(t,0,sizeof(t));
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(int i=x;i<=n;i++){
		cnt++;
		t[cnt]=a[i];
	}
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			if(t[i]==t[j]){
				vis[i]++;
				vis[j]--;
				i=j;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		f[i]=f[i-1]+vis[i];
	}
	for(int i=1;i<=cnt;i++){
		if(f[i]==0) s[t[i]]++;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",s[i]);
	}
	return 0;
}
