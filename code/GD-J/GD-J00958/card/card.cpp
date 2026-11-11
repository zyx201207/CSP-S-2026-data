#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
struct BIT{
	int c[N];
	int lowbit(int x){return x&-x;}
	void add(int x,int k){for(;x<N;x+=lowbit(x))c[x]+=k;return;}
	int ask(int l){int ret=0;for(;l;l-=lowbit(l))ret+=c[l];return ret;}
	int ask(int l,int r){return ask(r)-ask(l-1);}
}zch;
int n,m,a[N],pos[M],disp[M],ans[M];
bool vis[M],ap[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!ap[a[i]]){
			ap[a[i]]=1;
			ans[a[i]]=i;
		}
		if(vis[a[i]]){
			for(int j=i+1;j<pos[a[i]];j++)if(a[j]!=a[i]){
				vis[a[j]]=0;
				if(!disp[a[j]])disp[a[j]]=i;
			}
		}
		else if(disp[a[i]]){
			ans[a[i]]-=(disp[a[i]]-i);
			disp[a[i]]=0;
		}
		vis[a[i]]=1;
		pos[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
		if(disp[i])
			ans[i]-=disp[i];
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
