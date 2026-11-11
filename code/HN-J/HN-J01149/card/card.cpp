#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000001];
int b[1000001];
int c[1000001];
int f[1000001];
int d[1000001];
bool vis[1000001];
int tot;
int sum,sum1,sum2;
bool s,s1,s2;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=a[i];
	}
	sort(f+1,f+n+1);
	int qwq=1;
	d[1]=f[1];
	for(int i=2;i<=n;i++){
		if(f[i]!=f[i-1]){
			qwq++;
			d[qwq]=f[i];
		}
	}
	for(int w=1;w<=n;w++){ 
		for(int i=1;i<=m;i++){
			vis[i]=false;
		}
		for(int i=1;i<=n;i++){
			b[i]=n;
			tot=0;
		}
		for(int i=w;i<=n;i++){
			for(int j=1;j<=tot;j++){
				if(b[j]==a[i]){
					tot=j-1;
					break;
				}
			}
			tot++;
			b[tot]=a[i];
		}
		for(int i=1;i<=tot;i++){
			for(int j=1;j<=m;j++){
				if(b[i]==d[j] && vis[j]==false){
					c[d[j]]++;
					vis[j]=true;
					break;
				}
			}
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
