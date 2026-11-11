#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],id[M],ans[M],len,last[M];
bool vis[M],ok[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		last[a[i]]=i;
		if(a[i]<a[i-1]) flag=false;
	}
	if(flag){
		for(int i=1;i<=m;++i) cout<<last[i]<<" ";
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;++i){
			if(a[i]==a[n]) ++ans[a[i]];
			else ++ans[1],++ans[2];
		}
		cout<<ans[1]<<" "<<ans[2]<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(ok[i]) continue;
		if(a[i]==a[i-1]){
			for(int j=1;j<=len;++j) ++ans[id[j]];
			continue;
		}
		len=0;
		int num=0;
		for(int j=i;j<=n;++j){
			if(vis[a[j]]){
				if(a[j]==a[i]&&!ok[j]) ok[j]=1,++num;
				while(id[len]!=a[j]) vis[id[len--]]=0;
			}
			else id[++len]=a[j],vis[a[j]]=1;
		}
		for(int j=1;j<=len;++j) ans[id[j]]+=num+1,vis[id[j]]=0;
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
} 
