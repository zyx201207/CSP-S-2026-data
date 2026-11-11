#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int out[300005];
int nxt[300005];
int c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nxt[a[i]]=i;
	}for(int i=n;i>=1;i--){
		if(c[i]==0){
			c[i]=1;
		}
		if(a[i]==a[i-1]){
			c[i-1]=c[i]+1;
		}
	}
	for(int i=1;i<=n;i+=c[i]){
		for(int j=i;j<=n;j++){
			j=nxt[a[j]];
			out[a[j]]+=c[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<out[i]<<" ";
	}
	return 0;
}
