#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],q[10005],vis[10005],sum[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(q,0,sizeof(q));
		memset(vis,0,sizeof(vis));
		int h=1,t=1;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0||vis[a[j]]>t){
				vis[a[j]]=t;
				q[t++]=a[j];
			}
			else{
				t=vis[a[j]];
				q[t++]=a[j];
			}
		}
		for(int i=1;i<t;i++){
			sum[q[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
//48
