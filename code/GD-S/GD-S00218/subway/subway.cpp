#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int MAXM=5e5+5;
const int MAXQ=1e5+5;
unordered_map<int , bool>vis;
struct nom{
	int a,b,c;
};
struct node{
	unordered_map<int ,int>ln;//键值为线，里面存换乘时间 
	vector<int>v;
}st[MAXM];
struct line{
	int k;
	vector<int>v;
}ln[MAXN];
//vector<int>v[MAXM];
int c,n,m,d,Q;
int w[MAXM];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ln[i].k;
		for(int j=1;j<=ln[i].k;j++){
			int a,t;
			cin>>a>>t;
			ln[i].v.push_back(a);
			st[a].ln[i]=t;
			st[a].v.push_back(a);	
		}
	}
	while(Q--){
		vis.clear();
		int s,e;
		int ans = INT_MAX;
		cin>>s>>e;
		queue<pair<int,pair<int ,int> > >q;//首值为当前点，次值为目前花费
		for(int i=0;i<st[s].v.size();i++){// 											  	  一一 
			q.push(make_pair(s,make_pair(w[s]+w[e]+st[s].ln[st[s].v[i]],st[s].v[i])));//		|
		 } //																					|
		while(!q.empty()){//																	|
			int now=q.front().first,w=q.front().second.first,l=q.front().second.second;//		|
			if(st[e].ln[l]){//																	|
				ans=min(ans,w+st[e].ln[l]);//													|
			}//																					|
			q.pop();//																			|
			for(int i=0;i<st[now].v.size();i++){//												|这一部分写炸了但很神奇概率会过样例 
				for(int j=0;j<ln[st[now].v[i]].v.size();j++){//									|
					int x=ln[st[now].v[i]].v[j];//												|
					if(st[x].v.size()<2){//														|
						continue;//																|
					}//																			|
					else{//																		|
						if(!vis[x]){//															|
							vis[x]=1;	//														|
							q.push(make_pair(x,make_pair(w+st[now].ln[l]+st[now].ln[j],j)));//一一 
						}//
					}//
				}//
			}//
			
		}//
		cout<<ans<<endl;
	}
	return 0;
} 

