#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
long long c,t,n,d;
long long x[2345678];
int min_dist=0x3f3f3f3f,ways=0,theref=0;
struct Node{
	int idx,step;
};
//map<bool> vis;
//map<int> mem;
void bfs(int start,int end){
	min_dist=0x3f3f3f3f;
	queue<Node> q;
	q.push({start,0});
	while(!q.empty()){
		Node cur=q.front();
		q.pop();
		for(int pos=1;pos<=end-start;pos++){
			if(x[start+pos]-x[start]<=d){
				q.push({cur.idx+pos,cur.step+1});
				if(cur.idx==end){
					min_dist=cur.step;
					return;
				}
			}
			
			
		}
	}
}
void dfs(int pos,int idx,int step){
//	if(mem.count(pos)!=0)return mem[pos];
	if(pos==idx){
//		cout<<step<<"\n";
		if(step==min_dist)ways++;
		return;
	}
	for(int i=1;i<=pos-idx;i++){
		if(x[pos]-x[pos-i]<=d){
			dfs(pos-i,idx,step+1);
		}
	}
	
//	if(pos==idx){
//		if(step==min_dist)ways++;
//		return mem[pos]=ways;
//	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		int theref=0;
		ways=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ways=0;
				bfs(i,j);
				dfs(j,i,0);
				if(ways==2)theref++;	
			}
			
		}
		cout<<theref<<"\n";
		
	}
	
	return 0;
}
