#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000006],n,d,b[2000006],ans;
vector<int>vec[2000006];
struct node{
	int x,step;
}u,v;
void bfs(){
	queue<node>que;
	u.x=1;
	u.step=0;
	que.push(u);
	while(que.empty()==0){
		u=que.front();
		for(int i=u.x+1;i<=n;i++){
			if(abs(a[i]-a[u.x])<=d){
				v.x=i;
				v.step=u.step+abs(a[i]-a[u.x]);
				que.push(v);
				int flag=1;
				for(int j=vec[v.x][0];j<b[v.x];j++){
					if(vec[v.x][j]==v.step){
						ans++;
						flag=0;
						break;
					}
				}
				if(flag==1) vec[v.x].push_back(v.step);
			}
		}
		que.pop();
	}
}
int main(){
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		bfs();
		cout<<ans;
	}
}
