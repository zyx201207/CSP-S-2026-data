#include<bits/stdc++.h>
using namespace std;
int a[500005];
int vis[300005];
int ans[300005];
int l[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
queue<int> q;
for(int i=1;i<=n;i++){
	cin>>a[i];

}

for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++)vis[j]=0;
	int cnt=1;
	for(int j=i;j<=n;j++){
		if(vis[a[j]]==1){
		int bz=l[a[j]];
			for(int k=1;k<=m;k++){
			if(l[k]>=bz)vis[k]=0;
			}
		cnt=bz;
		}
		l[a[j]]=cnt++;
		vis[a[j]]++;
	}
	for(int j=1;j<=m;j++)if(vis[j]==1)ans[j]++;
}
for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
return 0;
}
