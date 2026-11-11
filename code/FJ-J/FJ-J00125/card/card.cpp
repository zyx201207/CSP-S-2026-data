#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],vis[10010];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		deque<int>q;
		map<int,bool>mp;
//		q.push_front( );
//		q.push_back( );
		for(int j=i;j<=n;j++){
			if(!mp[a[j]]){
				q.push_back(a[j]);
				mp[a[j]]=1;
			}else{
				while(!q.empty()&&q.back()!=a[j]){
					mp[q.back()]=0;
					q.pop_back();
				}
//				q.pop_nack();
//				q.push(a[j]);
//				mp[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(mp[j])vis[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
}
