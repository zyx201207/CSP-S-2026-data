#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int t=1;t<=n;t++){
		map<int,bool>f;
		queue<int> q;
		for(int i=t;i<=n;i++){
			int v=a[i];
			if(f[v]==0) q.push(v),f[v]=1;
			else{
				if(q.front()==v){
					while(!q.empty()) f[q.front()]=0,q.pop();
					q.push(v);f[v]=1;
					continue;
				}
				int fir=q.front();
				while(q.front()!=v){
					int e=q.front();
					q.pop();
					q.push(e);
				}
				while(q.front()!=fir) f[q.front()]=0,q.pop();
				q.push(v);f[v]=1;
			}
		}
		while(!q.empty()){
			ans[q.front()]++;
			q.pop();
		}
	}for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}


