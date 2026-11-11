#include<bits/stdc++.h>
#include<queue>
using namespace std;
int m,n,a[100005],ans[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		queue<int> q;
		queue<int> p;
		for(int j=i;j<n;j++){
			q.push(a[j]);
		}
		while(!q.empty()){
			int v=q.front();
			q.pop();
			queue<int> np;
			p.push(v);
			for(int i=0;i<p.size();i++){
				int u=p.front();
				p.pop();
				if(u==v){
					break;
				}
				np.push(u);
			}
			while(!p.empty()){
				p.pop();
			}while(!np.empty()){
				p.push(np.front());
				np.pop();
			}
			p.push(v);
		}
		while(!p.empty()){
			ans[p.front()]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
