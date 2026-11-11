#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e6+10;//O(n log V) 个 
int n,m,trie[N][2],siz[N];
int root,tot,val[N];
bool yz[N];
vector<int> VEC,vec; 
void insert(int x){
	int now=root;
	for(int i=29;i>=0;i--){//O(log V)
		int w=(x>>i)&1;
		if(!trie[now][w])trie[now][w]=++tot;
		now=trie[now][w];
		siz[now]++;
	}
	val[now]=x;
	yz[now]=1;
}
void dfs(int now){//O(n log V)
	if(yz[now]){//O(n)
		for(int i=1;i<=siz[now];i++)vec.push_back(val[now]);
		VEC.push_back(now);
		trie[now][0]=trie[now][1]=siz[now]=val[now]=yz[now]=0;
		return;
	}
	if(trie[now][0])dfs(trie[now][0]);
	if(trie[now][1])dfs(trie[now][1]);
	VEC.push_back(now);
	trie[now][0]=trie[now][1]=siz[now]=val[now]=yz[now]=0;
}
//一共 O(n log V) 次插入，一共有 O(n log V^2) 个节点，考虑合并后删掉这些被删的 
int query(int m){
	int now=root,res=0;
	for(int i=29;i>=0;i--){//log V
		if(trie[now][1]&&siz[trie[now][1]]>=m){//这一位能选 1 
			now=trie[now][1];
			res+=(1ll<<i);
		}else{//不能选 1，必然有 0，需要把 trie[now][0] 和 trie[now][1] 合并，应该是 n logn logm 的 
			if(trie[now][1]){
				vec.clear(),VEC.clear();
				dfs(trie[now][1]);
				int TOT=0;
				for(int j=0;j<(int)vec.size();j++){
					int a=vec[j]-(1ll<<i);
					int Now=root;
					for(int k=29;k>=0;k--){
						int w=(a>>k)&1;
						if(!trie[Now][w])trie[Now][w]=VEC[TOT++];
						Now=trie[Now][w];
						siz[Now]++;
					}
					val[Now]=a;
					yz[Now]=1;
				}
			}
			now=trie[now][0];
		}
	}
	return res;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	root=++tot;
	cin>>n>>m;
	for(int i=1,x;i<=n;i++)cin>>x,insert(x);
	cout<<query(m);//O(n log^2 V) = 1.8e8
	return 0;
}

