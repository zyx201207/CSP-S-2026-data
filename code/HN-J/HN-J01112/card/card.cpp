#include <bits/stdc++.h>
using namespace std;
/*
平庸下标：lst[a[i]]==i 
*/
int n,m,now;//当前最后一个不平庸下标 
int a[500005];
int lst[300005];
int vis[300005];
int cnt[300005];
int nxt[500005];
int sum[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],lst[a[i]]=i;
	for(int i=n;i>=1;i--){
		if(lst[a[i]]==i&&lst[a[i+1]]!=i+1) now=i;
		if(lst[a[i]]==i) nxt[i]=now;		
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt[a[j]]+=(vis[a[j]]!=i),vis[a[j]]=i;
			if(lst[a[j]]!=j) j=lst[a[j]];
			else sum[j+1]++,sum[nxt[j]+1]--,j=nxt[j];
		}
	}
	for(int i=1;i<=n;i++)
		sum[i]+=sum[i-1],cnt[a[i]]+=sum[i];
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int n,m,now;
int a[500005];
int lst[300005];
int vis[300005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],lst[a[i]]=i;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt[a[j]]+=(vis[a[j]]!=i),vis[a[j]]=i;
			if(lst[a[j]]!=j) j=lst[a[j]];
		}
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}
*/
