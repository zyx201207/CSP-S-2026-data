#include <iostream>
#include <cstdio>

struct Way {
	std::vector<std::pair<size_t,size_t>> nds;
};

struct Node {
	size_t idx;
	size_t w;
	std::vector<size_t> dis;
};

std::priority_queue<Node, std::vector<Node>,std::greater> que;


size_t n, m;
std::vector<Node> nodes;
std::vector<Way> ways;

void f() {
	for(Node i : nodes){
		while(que.size()){
			Node v = std::move(q.back());
			que.pop();
			for(Way j : ways) {
				for(std::pair k : j.nds){
					if(k.){
						
					}
				}
			}
		}
	}
}

int main(){
	{int c;std::cin >> c;}
	size_t d, q;
	std::cin >> n >> m >> d >> q;
	nodes.resize(m);
	for(size_t i = 1;i <= m;i++){
		std::cin >> nodes[i].w;
		nodes[i].idx = i;
		nodes[i].dis.resize(m, ULONG_LONG_MAX);
	}
	for(size_t i = 1;i <= n;i++){
		size_t k;
		std::cin >> k;
		Way tmp;
		while(k--){
			size_t to, t;
			std::cin >> to >> t;
			tmp.nds.push_back({to,t});
		}
		ways.push_back(std::move(tmp));
	}
	f();
	while(q--){
		size_t a,b;
		std::cin >> a >> b;
		std::cout << nodes[a].w + nodes[a].dis[b] + nodes[b].w << '\n';
	}
}

