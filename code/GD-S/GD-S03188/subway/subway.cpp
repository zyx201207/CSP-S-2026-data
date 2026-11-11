#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0ll,f=1ll;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int c,n,m,d,q,ans;
int w[500100],a[510][500100],t[510][500100];
void dfs(int x,int y,int sum,int l,int d){
	if(x==y){
		ans=min(ans,sum);
		return;
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		a[i][0]=k;
		for(int j=1;j<=k;j++){
			a[i][j]=read();
			t[i][j]=read();
		}
	}
	while(q--){
		int x=read(),y=read(); 
	}
	return 0;
}
