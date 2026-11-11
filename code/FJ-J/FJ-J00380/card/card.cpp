#include<bits/stdc++.h>
using namespace std;
//struct node{
//	int l,r;
//	friend bool operator < (node x,node y){
//		return x.l<y.l;//大根堆 
//	}
//};
int n,m;
int a[500005];
int ans[300005];//答案，通过贡献计算
bool vis[300005]; 
//int lst[500005];
//vector<int>pos[300005];
//priority_queue<node>q;
//queue<node>qq;
//queue<node>ls;
stack<int>now; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i&&a[i]<a[i-1]){
			flag=0;
		}
//		pos[a[i]].push_back(i);
	}
	if(flag){
		cout<<m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				now.push(a[j]);
				vis[a[j]]=1;
			}else{
				while(now.top()!=a[j]){
					vis[now.top()]=0;
					now.pop();
				}
			}
		}
		while(!now.empty()){
			ans[now.top()]++;
			vis[now.top()]=0;
			now.pop();
		}
	}
//	for(int i=1;i<=n;i++){
//		while(!q.empty()&&q.top().r<=i){
//			qq.push(q.top());//qq保证按l从大到小依次 
//			q.pop();
//		}
//		if(!q.empty()){
//			lst[i]=q.top().l;
//		}else{
//			lst[i]=0;
//		}
//		if(pos[a[i]][pos[a[i]].size()-1]!=i){//这个点后方有个颜色相同的，会被消 
//			q.push({i,pos[a[i]][pos[a[i]].size()-1]});
////			cout<<i<<" "<<pos[a[i]][pos[a[i]].size()-1]<<"\n";
//			continue;
//		}
//		ans[a[i]]+=i-lst[i];
//		int mn=lst[i];
//		while(!qq.empty()){
//			while(!q.empty()&&q.top().l>=qq.front().l){//如果有个本来能消得去见被笑了 
//				ls.push(q.top());
//				q.pop();
//			}
//			if(q.empty()){
//				mn=0;
//			}else{
//				mn=q.top().l;
//			}
//			if(qq.front().l<=lst[i]&&qq.front().r>=lst[i]){//恰好是消掉lst[i]不消掉i的 
//				ans[a[i]]+=qq.front().l-mn;
//			}
//			qq.pop();
//		}
//		while(!ls.empty()){
//			q.push(ls.front());
//			ls.pop();
//		}
//	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
