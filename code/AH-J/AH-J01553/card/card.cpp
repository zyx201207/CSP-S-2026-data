#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5,M=3*1e5+5;
int n,m;
int a[N];
int vis[M];
int t[M];
int tt[M];
int sum[M];
int q[N];
int tail;
bool flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		tt[a[i]]++;
		if(a[i]<a[i-1]){
			flag=0;
		}
	}
	if(flag){
		for(int i=1;i<=m;i++){
			sum[i]=sum[i-1]+tt[i];
			cout << sum[i] << " ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(q,0,sizeof(q));
		memset(vis,0,sizeof(vis));
		tail=0;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				q[++tail]=a[j];
				vis[a[j]]=tail;
			}else{
				for(int k=vis[a[j]]+1;k<=n;k++){
					vis[q[k]]=0;
				}
				tail=vis[a[j]];
			}
		}
		for(int i=1;i<=tail;i++){
			t[q[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << t[i] << " ";
	}
	return 0;
}


