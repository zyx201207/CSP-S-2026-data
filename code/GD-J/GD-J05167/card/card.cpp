#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b1[200005],b2[200005],vis[200005];
stack<int>q;
void reset(){
	while(!q.empty())q.pop();
	memset(b2,0,sizeof b2);
	memset(vis,0,sizeof vis);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		
	}
	for(int i=1;i<=n;i++){
		reset();
		for(int j=1;j<=n;j++){
			if(b2[a[j]]>0){
				while(q.top()!=a[j]){
					b2[q.top()]--;
					q.pop();
				}
				b2[a[j]]--;
				q.pop();
			}
			q.push(a[j]);
			b2[a[j]]++;
		}
		while(!q.empty()){
			if(vis[q.top()]==0){
				vis[q.top()]=1;
				b1[q.top()]++;
			}
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<b1[i]<<" ";
	return 0;
}
