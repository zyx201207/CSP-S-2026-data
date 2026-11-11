#include <bits/stdc++.h>
using namespace std;
int n,m,v[500005];
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int q[500005]={0};
		int tt=-1;
		int vis[500005]={0},s[500005]={0};
		for(int j=i;j<=n;i++){
			if(vis[a[i]]){
				for(int i=s[a[i]];i<=tt;i++) vis[q[i]]=0;
				tt=s[a[i]];
				q[tt]=a[i];
				vis[a[i]]=1;
			}
			else{
				q[++tt]=a[i];
				s[a[i]]=tt;
				vis[a[i]]=1;
			}
		}
		for(int k=0;k<=tt;k++) v[q[k]]++;
	}
	for(int i=1;i<=m;i++){
		if(!v[i]) continue;
		cout<<v[i]<<" ";
	}
	return 0;
}
