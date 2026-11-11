#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans,a;
int x[N];
bool flag[N];
deque<int> dq;
void dfs(){
	if(dq.size()>=m){
		int keep=INT_MAX;
		queue<int> q;
		while(dq.size()){ 
			keep&=x[dq.front()];
			q.push(dq.front());
			dq.pop_front();
		}
		ans=max(keep,ans);
		while(q.size()){
			dq.push_back(q.front());
			q.pop();
		}				
		return;
	}
	int st;
	if(dq.empty()) st=++a;
	else st=dq.front();
	for(int i=st;i<=n;i++){
		if(!flag[i]){
			dq.push_back(i);
			flag[i]=true;
			dfs();
			dq.pop_back();
			flag[i]=false;
		}
	}
	dq.pop_back();
	dfs();
	return;	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	dfs();
	cout<<ans<<endl;
	return 0;
}
