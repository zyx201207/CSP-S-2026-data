#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+101;
int n,m,s[N],dis[N],vis[N],b[N],c[N];
struct node{
	int a,id;
}q[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		q[i].a=s[i];
		q[i].id=i;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(vis[q[j].a]==1){
				c[q[j].a]=j;
			}else{
				vis[q[j].a]=1;
				b[q[j].a]=j;
				c[q[j].a]=j;
			}
		} 
		int s=c[q[i].a]+1;
		dis[q[i].a]++; 
		while(s){
			if(s>n)break;
			if(s==n){
				dis[q[s].a]++;
				break;
			}else{
				dis[q[s].a]++;
				s=c[q[s].a]+1;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<dis[i]<<" ";
	return 0;
} 
