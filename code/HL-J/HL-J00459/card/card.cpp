#include<bits/stdc++.h>
using namespace std;
int n,m;
struct iks{
	bool f=0;
	int inx;
};
int a[500006],ans[300006];
long long l,sum;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		deque<int> q;
		iks vis[500006];
		for(int i=t;i<=n;i++){
			if(!vis[a[i]].f){
				vis[a[i]].f=1;
				vis[a[i]].inx=i;
				q.push_front(a[i]);
			}else{
				for(int j=vis[a[i]].inx;j<i;j++){
					q.pop_back();
				}
				q.push_front(a[i]);
				vis[a[i]].f=1;
				vis[a[i]].inx=i;
			}
		}
		while(!q.empty()){
			int x=q.front();
			ans[x]++;
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
    return 0;
}
