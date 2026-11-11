#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],nx[M],nxt[N];
int p[M],ans[M];
int read(){
	char c=getchar();
	int ans=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		nx[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		nxt[i]=nx[a[i]];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			if(p[a[j]]!=i) p[a[j]]=i,ans[a[j]]++;
			if(nxt[j]!=j) j=nxt[j];
			else j++;
		}
	}
	for(int j=1;j<=m;j++){
		printf("%d ",ans[j]);
	}
	return 0;
}
