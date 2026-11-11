//GZ-J00394 姓名：周昊杨 学校：贵阳市第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],vis[N],cnt[N],ma,flag,v[N];
deque<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])flag=1;
	}
	if(!flag){
		
		return 0;
	}
	for(int i=1;i<=n;i++){
		int st=i;
		memset(vis,0,sizeof(vis));
		memset(v,0,sizeof(v));
		
		while(!q.empty())q.pop_back();
		
		for(int j=st;j<=n;j++){
			if(vis[a[j]]){
				while(a[q.back()]!=a[j]){
					vis[a[q.back()]]=0;
					q.pop_back();
				}
			}
			q.push_back(j);
			vis[a[j]]=1;
		}
		for(int i=1;i<=m;i++)cnt[i]+=vis[i];
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}

