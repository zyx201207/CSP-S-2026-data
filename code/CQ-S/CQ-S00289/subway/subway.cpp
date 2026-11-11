#include<bits/stdc++.h>
using namespace std;
//双向任意通行 
int c,n,m,d,q;
set<int>s[5001];//第i条路线是否通向某个车站 
int w1[500005];//地铁口到站台 
int w2[505][500001];//地铁路线到站厅
int w3[505][505];//从地铁路线i到地铁路线j的最小花费站口
deque<int>qp[500005];//经过第i个地铁站的地铁路线编号
queue<int>h;
long long ans=INT_MAX;
bool vi[500005];
void dfs(int x,int go,long long w){
//	cout<<x<<" "<<go<<" "<<w<<endl;
	if(x==go){
		w+=w1[x];
		ans=min(ans,w);
		return;
	}
	bool flag=0;
	for(int i=1;n>=i;i++){
		if(w2[i][x]!=INT_MAX && w2[i][go]!=INT_MAX){
			w+=w2[i][x]+w2[i][go]+w1[go];
			ans=min(ans,w);
			w-=w2[i][x]+w2[i][go]+w1[go];
			flag=1;
		}
	}
	if(flag==1)return;
	for(int i=1;n>=i;i++){
		if(w2[i][x]!=INT_MAX){
			for(int j=1;n>=j;j++){
				if(w3[i][j] && !vi[w3[i][j]] && i!=j){
					vi[w3[i][j]]=1;
					dfs(w3[i][j],go,w+w2[i][x]+w2[i][w3[i][j]]);
					vi[w3[i][j]]=0;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;m>=i;i++)cin>>w1[i];
	for(int i=0;n>=i;i++){
		for(int j=0;m>=j;j++)w2[i][j]=INT_MAX;
	}
	for(int i=1;n>=i;i++){
		int k;
		cin>>k;
		for(int j=1;k>=j;j++){
			int a,t;
			cin>>a>>t;
			qp[a].push_back(i);
			w2[i][a]=t;
			s[i].insert(a); 
		}
	}
	for(int i=1;m>=i;i++){
		int sum=qp[i].front();
		h.push(qp[i].front());
		qp[i].pop_front();
		while(!qp[i].empty()){
			while(!qp[i].empty()){
				if(!w3[sum][qp[i].front()] ||w2[qp[i].front()][i]+w2[sum][i]<w2[qp[i].front()][w3[qp[i].front()][sum]]+w2[sum][w3[qp[i].front()][sum]]){
				w3[sum][qp[i].front()]=i;
				w3[qp[i].front()][sum]=i;
			}
			h.push(qp[i].front());
			qp[i].pop_front();
			}
			h.pop();
			while(!h.empty()){
				qp[i].push_back(h.front());
				h.pop();
			}
		}
		
	}
	while(q--){
		ans=INT_MAX;
		int x,y;
		cin>>x>>y;
		vi[x]=1;
		dfs(x,y,w1[x]);
		vi[x]=0;
		cout<<ans<<endl;
	}
}
