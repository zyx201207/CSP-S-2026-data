#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=3e5+5;
int ton[N],a[N],v[N],last[N];
bool vis[N];
int n,idx,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	//暴力模拟题意写法 
	for(int i=1;i<=n;i++){
		idx=0;
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
//			cout<<last[a[j]]<<' ';
			if(vis[a[j]]){
				for(int k=last[a[j]];k<idx;k++)vis[v[k]]=0;
				idx=last[a[j]]+1;
				continue;
			}
			last[a[j]]=idx;
			v[idx++]=a[j];
			vis[a[j]]=1;
		}
//		cout<<'\n';
		memset(vis,0,sizeof vis);
		for(int j=0;j<idx;j++)ton[v[j]]+=(!vis[v[j]]),vis[v[j]]=1;
	}
	for(int i=1;i<=m;i++)cout<<ton[i]<<' ';
	return 0;
}
