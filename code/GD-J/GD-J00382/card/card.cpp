#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N],p[N],lst[N],nxt[N],c[N],ans[N];
bool g[N];
int sk[N],h=1,t,he[N],l[N],mx[N];
void add(int i,int v){
	for(;i<=n;i+=(i&(-i)))mx[i]=max(mx[i],v);
}
int qur(int i){
	int ans=0;
	for(;i;i-=(i&(-i)))ans=max(mx[i],ans);return ans;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)nxt[i]=n+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[i]=p[a[i]];nxt[p[a[i]]]=i;
		p[a[i]]=i;he[a[i]]=1;
	}
	
	for(int i=1;i<=n;i++){
		int q=qur(n-i); 
		c[i]=i-q,l[i]=q;
		if(nxt[i]<=n)add(n-nxt[i]+1,i);
	}
	for(int i=n;i>=1;i--){
		if((nxt[i]==n+1||i<=l[nxt[i]])&&he[a[i]]){
			ans[a[i]]+=c[i];
		}else he[a[i]]=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
/*
   1 2 1 3   2
*/
