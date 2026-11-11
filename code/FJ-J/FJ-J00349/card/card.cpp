#include<bits/stdc++.h>
using namespace std;
const int maxm=3e5+5,maxn=5e5+5;
int ans[maxm];bool vis[maxm];
inline int rea(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}c=getchar();
	}while(c<='9'&&c>='0'){
		x*=10;x+=c-'0';
		c=getchar();
	}return x*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=rea(),m=rea();deque<int>q;
	if(n>4000){
		int x,y;
		for(int i=0;i<n;i++){
			y=rea();
			if(i&&y!=x){
				cout<<i<<' ';
			}x=y;
		}cout<<n;
	}
	else{
	for(int i=n;i;--i)q.emplace_back(rea());
	for(int i=n;i;--i){
		memset(vis,0,sizeof vis);
		deque<int>e=q;
		stack<int>s;
		while(e.size()){
			int t=e.front();
			if(vis[t]){
				while(s.top()!=t){
					vis[s.top()]=0;s.pop();
				}s.pop();
			}s.push(t);vis[t]=1;
			e.pop_front();
		}while(s.size()){
			ans[s.top()]++;s.pop();
		}q.pop_front();
	}cout<<ans[1];
	for(int i=2;i<=m;i++)printf(" %d",ans[i]);}
	return 0;
}
