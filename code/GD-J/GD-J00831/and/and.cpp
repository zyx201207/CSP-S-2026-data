#include<iostream>
#include<vector>
using namespace std;
const int N=2e5+5;
int n,m,a[N],cnt[35],ans;
vector<int> g;
bool vis[N];
void insert(int x){
	for(int i=30;i>=0;i--){
		if(x&(1<<i)) cnt[i]++;
	}
}
int ffind(){
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m){
			cnt[i]=0;
			return i;
		}
	}
	return -1;
}
void update(int tmp){
	for(int i=0;i<g.size();i++){
		if(vis[i]) continue;
		if(!(g[i]&(1<<tmp))){
			for(int j=30;j>=0;j--){
				if(g[i]&(1<<j)) cnt[j]--;
			} 
			vis[i]=1;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g.push_back(a[i]);
		insert(a[i]);
	}
	int x=ffind();
	while(x!=-1){
		ans|=(1<<x);
		update(x);
		x=ffind();
	}
	cout<<ans;
}//10:40
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
