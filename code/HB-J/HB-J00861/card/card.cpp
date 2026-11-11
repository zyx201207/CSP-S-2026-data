#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],ans[M],b[M];
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(!q.empty()){
					q.pop();
				}
			}
			q.push(a[j]);
			b[a[j]]=1;
		}
		while(!q.empty()){
			int x=q.front();
			ans[x]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
