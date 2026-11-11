#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,head[M];
int arr[N];
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
	}
	int t=0;
	while(++t<=n){
		deque<int> q;
		q.clear();
		memset(vis,0,sizeof(vis));
		for(int i=t;i<=n;++i){
			if(vis[arr[i]]){
				while(true){
					int tmp=q.back();
					if(tmp==arr[i])break;
					vis[tmp]=false;
					q.pop_back();
				}
			}else{
				vis[arr[i]]=true;
				q.push_back(arr[i]);
			}
		}	
		while(!q.empty()){
			int tmp=q.front();
			++head[tmp];
			q.pop_front();
		}
	}
	for(int i=1;i<=m;++i){
		printf("%d ",head[i]);
	}
	return 0;
}
