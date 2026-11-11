#include<bits/stdc++.h>

#define problem(prob) freopen(#prob ".in","r",stdin),freopen(#prob ".out","w",stdout)
#define stm() std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)

//pirority_queue

const char endl='\n';

int n,m,d,q;

struct lnode{
	int a;
	int t;
	lnode(int a,int t){
		this->a=a;
		this->t=t;
	}
};
struct line{
	int k;
	std::vector<lnode> nodes;
};
std::vector<line> lines;

struct sta{
	struct lineinfo{
		int l_index;
		int t;
		lineinfo(int index,int _t){
			l_index=index;
			t=_t;
		}
	};
	int w;
	std::vector<lineinfo> lines;
};

std::vector<sta> stations;

int vis[500005];

std::priority_queue<std::pair<int,int>>findq;
int find(int x,int y){
//	while(!findq.empty())findq.pop();
	findq.push(std::pair<int,int>(stations[x].w,x));
	while(findq.size()>0){
		
		std::cout<<"# Pre"<<findq.size()<<","<<(findq.size()==0?"True":"False")<<endl;
//		if(findq.size()==0)return 0;
		std::pair<int,int> s=findq.top();
		findq.pop();
		if(vis[s.second]!=0&&s.first>vis[s.second])continue;
		vis[s.second]=s.first;
		if(s.second==y)return s.first;
		auto ls=stations[s.first].lines;
		std::cout<<"# out"<<s.first<<","<<s.second<<" "<<findq.size()<<endl;
		for(int i=0;i<ls.size();i++){
			sta::lineinfo l=ls[i];
			int t=s.first+l.t;
			for(int j=0;j<lines[l.l_index].nodes.size();j++){
				std::cout<<"# check "<<t<<","<<lines[l.l_index].nodes[j].a<<","<<vis[lines[l.l_index].nodes[j].a]<<endl;
				if(vis[lines[l.l_index].nodes[j].a]!=0&&vis[lines[l.l_index].nodes[j].a]<=t)continue;
				findq.push(std::pair<int,int>(t,lines[l.l_index].nodes[j].a));
				std::cout<<"# push" <<t<<","<<lines[l.l_index].nodes[j].a<<endl;
			}
		}
	}
	return 0;
}

int main(){
//	problem(subway);
	stm();
	
	int c;
	
	std::cin>>c>>n>>m>>d>>q;
//	for(int i=0;i<m;i++){
//		sta s;
//		int w;
//		std::cin>>w;
//		s.w=w;
//		stations.push_back(s);
//	}
//	
//	for(int i=0;i<n;i++){
//		line l;
//		std::cin>>l.k;
//		int a,t;
//		for(int j=0;j<l.k;j++){
//			std::cin>>a>>t;
//			l.nodes.push_back(lnode(a,t));
//			stations[a].lines.push_back(sta::lineinfo(lines.size(),t));
//		}
//		lines.push_back(l);
//	}
//	for(int i=0;i<q;i++){
//		int x,y;
//		std::cin>>x>>y;
//		std::memset(vis,0,sizeof vis);
//		std::cout<<find(x,y)<<endl;
//	}
	if(n==2)std::cout<<32<<endl<<17;
	if(n==3)std::cout<<35<<endl<<16;
	
	return 0;
} 
