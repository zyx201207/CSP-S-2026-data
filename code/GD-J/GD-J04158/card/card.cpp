#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],nxt[M],val[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)nxt[j]=0;
		int tp=0;
		for(int j=i;j<=n;++j){
			if(!nxt[a[j]])nxt[a[j]]=j;
			else tp=nxt[a[j]]-1;
			val[++tp]=a[j];
		}
		for(int i=1;i<=tp;++i)++ans[val[i]];
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
	return 0;
}
