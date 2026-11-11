#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],x,cnt[500005],nl,f[300005];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		nl=0;
		for(int j=i;j<=n;j++)q.push(a[j]);
		while(!q.empty()){
			x=q.front();
			if(f[x]!=0){
				for(int j=f[x]+1;j<=nl;j++){
					f[cnt[j]]=0;
					cnt[j]=0;
				}
				nl=f[x];
			}
			else{
				cnt[++nl]=x;
				f[x]=nl;
			}
			q.pop();
		}
		for(int j=1;j<=nl;j++){
			ans[cnt[j]]++;
			f[cnt[j]]=0;
			cnt[j]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
