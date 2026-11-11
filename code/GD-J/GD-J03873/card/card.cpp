#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

int n,m;
int a[N],lst[N],pre[N];
int ans[N];
int ex[N],cur[N],siz;
bool vis[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(lst,-1,sizeof lst);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		siz=0;
		memset(ex,-1,sizeof ex);
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(pre[j]!=-1&&pre[j]>=i&&ex[a[j]]!=-1){
				int t=siz;
				siz=ex[a[j]]-1;
				for(int k=ex[a[j]];k<=t;k++){
					ex[cur[k]]=-1;
				}
			}
			cur[++siz]=a[j];
			ex[a[j]]=siz;
		}
		for(int j=1;j<=siz;j++){
//			cout<<cur[j]<<' ';
			if(!vis[cur[j]]){
				ans[cur[j]]++;
				vis[cur[j]]=1;
			}
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

5 3
2 3 1 2 1
*/
