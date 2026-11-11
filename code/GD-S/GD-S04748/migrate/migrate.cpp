#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
struct node{
	int x,step;
};
int c,t,a[N],f[N],vis[N],s[N],cnt;
void bfs(int n,int d){
	queue<node>q;
	q.push({1,0});
	while(q.size()){
		int x=q.front().x,step=q.front().step;
		q.pop();
		for(int i=1;i<=d;i++){
			if(!vis[x+i]&&x+i<=a[n]){
				vis[x+i]++;
				q.push({x+i,step+i});
				f[x+i]++;
				if(s[x+i]==step+i&&f[x+i]==2){
					cnt++;
				}
				s[x+i]=step+i;
			}
			if(!vis[x-i]&&x-i>=a[1]){
				vis[x-i]++;
				q.push({x-i,step+i});
				f[x-i]++;
				if(s[x-i]==step+i&&f[x-i]==2){
					cnt++;
				}
				s[x-i]=step+i;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bfs(n,d);
		cout<<cnt<<"\n";
	}
	return 0;
}

