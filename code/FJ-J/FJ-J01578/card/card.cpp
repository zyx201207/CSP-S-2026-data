#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
bool vis[M];
int id[M],cnt[M];
int a[N];
int b[N];
int size=0;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(!vis[a[j]]) {
				vis[a[j]]=1;
				size++;
				id[a[j]]=size;
				b[size]=a[j];
			} else {
				for(int k=id[a[j]]+1;k<=size;k++){
					vis[b[k]]=0;
					b[k]=0;
				}
				size=id[a[j]];
			}
		}
		for(int i=1;i<=size;i++){
			cnt[b[i]]++;
		}
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		size=0;
	}
	for(int i=1; i<=m; i++) {
		cout<<cnt[i]<<' ';
	}
	return 0;
}

