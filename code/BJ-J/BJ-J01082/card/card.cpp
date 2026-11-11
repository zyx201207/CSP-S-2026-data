#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[300001],d[500001],a[500001],lst[500001],cnt[300001];
bool vis[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		lst[i]=s[a[i]];
		s[a[i]]=i;
	}
	for (int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for (int j=n-i+1;j<=n;j++){
			if (lst[j]>=n-i+1){
				d[j]++;
				d[lst[j]]--;
			}
		}
		int q=1;
		for (int j=n-i+1;j<=n;j++){
			q+=d[j];
			if (q==1)vis[j]=1;
		}
		for (int j=1;j<=n;j++){
			cnt[a[j]]+=vis[j];
		}
	}
	for (int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	cout<<endl;
	return 0;
}
