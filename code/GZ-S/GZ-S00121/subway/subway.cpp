//GZ-S00121 遵义市南白中学 卢杰子豪 

#include<fstream>
#include<vector>
#include<queue>

std::ofstream out("subway.out");
std::ifstream in("subway.in");

using ull = unsigned long long;

constexpr int max_size=1e6+600;

struct Node
{
	std::vector<int> to;
	std::vector<ull> w;
	
	bool is_min;
	ull min;
	int min_id=-1;
}nodes[max_size];

void push(int i,int j,ull w)
{
	auto& ni=nodes[i];
	auto& nj=nodes[j];
	ni.to.push_back(j);
	ni.w.push_back(w);
	nj.to.push_back(i);
	nj.w.push_back(w);
}

struct GNode
{
	bool operator()(int a,int b)
	{
		return nodes[a].min>nodes[b].min;
	}
};

struct Query
{
	int x,y;
	ull min=-1ull;
};
std::vector<Query> query;

void dijkstra(int root)
{
	std::priority_queue<int,std::vector<int>,GNode> queue;
	nodes[root].min=0;
	nodes[root].min_id=root;
	nodes[root].is_min=false;
	queue.push(root);
	
	while(!queue.empty())
	{
		int top=queue.top();
		queue.pop();
		auto& node=nodes[top];
		if(node.is_min)continue;
		node.is_min=true;
		
		for(int i=0;i<node.to.size();i++)
		{
			auto& ch=nodes[node.to[i]];
			if(ch.min_id!=root)
			{
				ch.is_min=false;
				ch.min=-1ull;
				ch.min_id=root;
			}
			if(ch.is_min)continue;
			if(node.w[i]+node.min<ch.min)
			{
				ch.min=node.w[i]+node.min;
				queue.push(node.to[i]);
			}
		}
	}
	for(auto& qry:query)
	{
		ull tmin=nodes[qry.x].min+nodes[qry.y].min;
		if(tmin<qry.min)qry.min=tmin;
	}
}
int main()
{
	int c,n,m,d,q;
	in>>c>>n>>m>>d>>q;
	int nm=n+m;
	for(int i=1;i<=m;i++)
	{
		ull w;
		in>>w;
		push(n+i,nm+i,w);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		in>>k;
		while(k--)
		{
			int a;
			ull t;
			in>>a>>t;
			push(i,n+a,t);
		}
	}
	
	query.resize(q);
	for(auto& qry:query)
	{
		in>>qry.x>>qry.y;
		qry.x+=nm;
		qry.y+=nm;
	}
	
	for(int i=1;i<=n;i++)
		dijkstra(i);
	
	for(auto& qry:query)
		out<<qry.min<<'\n';
	return 0;
}
