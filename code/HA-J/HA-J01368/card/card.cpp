#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],c[300010],d[300010];
bool e[500010];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=d[a[i]];
		d[a[i]]=i;
	}
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		memset(e,0,sizeof(e));
		for(int j=i;j<=n;j++){
			c[a[j]]++;
			if(b[a[j]]&&!e[j]){
				for(int k=j;k>b[a[j]];k--){
					c[a[k]]--;
					e[k]=1;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(c[j]){
				d[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
