#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],vis[N],cnt[N];
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0') x=x*10+(c-'0'),c=getchar();
	return f*x;
}
void moni(int s){
	vector<int> q;
	q.clear();
	for(int i=1;i<=m;i++)cnt[i]=0;
	for(int i=s;i<=n;i++){
		int u=a[i];
		if(cnt[u]==1) q.push_back(u);
		else{
			q.clear();
			q.push_back(u);
			for(int i=1;i<=m;i++)cnt[i]=0;
		}
	}
	for(int i=0;i<=q.size();i++)ans[q.front()]++,q.erase(q.begin());
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read(),vis[a[i]]=1;
	for(int i=1;i<=n;i++) moni(i);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
