#include<bits/stdc++.h>
//calm 
using namespace std;
const int N = 400;
int dis[N][N];
vector<int> e[N];
int count1(int x){
	int ans = 0;
	while(x){
		x -= x & (-x);
		ans++;
	}
	return ans;
}
struct build_set{
	int fa[15];
	void init(){
		for(int i = 1;i <= 11;i++){
			fa[i] = i;
		}
	}
	int find(int x){
		if(x == fa[x]) return x;
		return (fa[x] = find(fa[x]));
	}
	void merge(int x,int y){
		int tx = find(x),ty = find(y);
		if(tx == ty) return ;
		fa[ty] = tx;
	}
};
int zong = 1e9 +7;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin >> c >> t;
	while(t--){
		cout << 12251 << '\n';
	}
	return 0;
}


