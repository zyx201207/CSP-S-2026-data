#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
struct Node{
	int x;
	int next;
}a[N],now,newa[N]; 
int n,m,ans[M],vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		a[i].x=t,a[i].next=(i+1)%(n+1);
	}
	for(int nown=1;nown<=n;nown++){
		memset(vis,0,sizeof(vis));
		for(int i=nown;i<=n;i++)newa[i].x=a[i].x,newa[i].next=a[i].next;
		int nowi=nown;
		for(int i=1;;i++){
			now=newa[nowi];
			if(now.x==0)break;
			if(vis[now.x]!=0){
				int li=i;
				i=vis[now.x];
				newa[vis[now.x]].next=now.next;
				for(int k=i;k<li;k++)vis[newa[k]]=0;
			}
			vis[now.x]=i;
			nowi=now.next;
		}
		now=newa[nown];
		while(now.x!=0){
			ans[now.x]++;
			now=newa[now.next];
		}	
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
