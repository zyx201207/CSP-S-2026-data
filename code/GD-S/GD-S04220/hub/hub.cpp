#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 20;
const int M = 3e3 + 20;
int my_id,T;
int n,k;
int my_u[N],my_v[N];
int fl[N],b[N],my_len = 0;
vector<int> son[N];
int dis[M][M],mn[N];
int my_lst_ans;
void dfs2(int y,int x,int fa,int dep){
	int len = son[x].size();
	dis[y][x] = dep;
	for(int i = 0;i < len;i++){
		if(son[x][i] == fa) continue;
		dfs2(y,son[x][i],x,dep + 1);
	}
	return ;
}
int my_fa[N];
int my_find(int x){
	while(x != my_fa[x]) x = my_fa[x] = my_fa[my_fa[x]];
	return x;
}
void merge(int x,int y){
	int my_fx = my_find(x),my_fy = my_find(y);
	if(my_fx == my_fy) return ;
	my_fa[my_fy] = my_fx;
	return ;
}
void dfs(int x,int y){
	if(x > n && y > 0) return ;
	else if(y == 0){
		my_len = 0;
		int my_tmp_ans = -1000000000;
		for(int i = 1;i <= n;i++){
			mn[i] = 1000000000;
			for(int j = 1;j <= n;j++) dis[i][j] = 0;
		}
		for(int i = 1;i <= n;i++){
			
			
			if(fl[i]){
				
				dfs2(i,i,-1,0);	
				for(int j = 1;j <= n;j++){
					mn[j] = min(mn[j],dis[i][j]);
					
				}
			}
			
		}
		
		
		for(int i = 1;i <= n;i++){
			my_tmp_ans = max(my_tmp_ans,mn[i]);
			my_fa[i] = i;
		}
		for(int i = 1;i < n;i++){
			if(fl[my_u[i]] == 1 && fl[my_v[i]] == 1){
				merge(my_u[i],my_v[i]);
			}
		}
		int my_tmp_cnt = 0;
		for(int i = 1;i <= n;i++){
			if(fl[i] == 1 && my_fa[i] == i){
				my_tmp_cnt++;
			}
		}
		
		if(my_tmp_cnt <= 2) my_lst_ans = min(my_lst_ans,my_tmp_ans);
		
		
	}else{
		fl[x] = 1;
		dfs(x + 1,y - 1);
		fl[x] = 0;
		dfs(x + 1,y);
	}
}
void solve(){
	cin >> n >> k;
	for(int i = 1;i < n;i++){
		cin >> my_u[i] >> my_v[i];
		son[my_u[i]].push_back(my_v[i]);
		son[my_v[i]].push_back(my_u[i]);
	}
	if(n <= 16){
		my_lst_ans = 1000000000;
		dfs(1,k);
		cout << my_lst_ans << '\n';
	}
	for(int i = 1;i <= n;i++){
		my_fa[i] = i;
		fl[i] = 0;
		son[i].clear();
		for(int j = 1;j <= n;j++){
			dis[i][j] = 0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> my_id >> T;
	while(T--){
		solve();	
	}
}
