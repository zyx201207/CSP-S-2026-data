#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
long long a[500010],n,m,vis[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	int x=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	while(x<n){
		x++;
		stack<int> q;
		for(int i=1;i<=m;i++)
			vis[i]=0;
		for(int i=x;i<=n;i++){
			if(vis[a[i]]==0){
				q.push(a[i]);
			}else{
				if(!q.empty()&&q.top()!=a[i]){
					vis[q.top()]--;
					q.pop();
				}	
			}
			if(vis[a[i]]==0){
				vis[a[i]]=1;
			}	
		}
		for(int i=1;i<=m;i++){
			if(vis[i])
				ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
