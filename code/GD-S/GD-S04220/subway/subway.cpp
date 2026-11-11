#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 20;
const int M = 601;
int my_id,n,m,d,q;
int a[N];
long long dis[M][M],vis[M][M];
long long my_len[N],my_tmp_x,my_tmp_y,len_v[N];
long long v[N][22],t[N][22];
long long tmp[M][M];
void floyd(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				tmp[j][k] = min(tmp[j][k],tmp[j][i] + tmp[i][k]);
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> my_id >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> my_len[i];
		for(int j = 1;j <= my_len[i];j++){
			cin >> my_tmp_x >> my_tmp_y;
			len_v[my_tmp_x]++;
			v[my_tmp_x][len_v[my_tmp_x]] = i;
			t[my_tmp_x][len_v[my_tmp_x]] = my_tmp_y;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			tmp[i][j] = 1000000000000000000ll;
			if(i == j) tmp[i][j] = 0ll;
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= len_v[i];j++){
			for(int k = j + 1;k <= len_v[i];k++){
				long long pp = t[i][j],qq = t[i][k];
				tmp[v[i][j]][v[i][k]] = min(tmp[v[i][j]][v[i][k]],pp + qq);
				tmp[v[i][k]][v[i][j]] = min(tmp[v[i][k]][v[i][j]],pp + qq);
			}
		}
	}
	floyd();
	while(q--){
		cin >> my_tmp_x >> my_tmp_y;
		long long my_part_answ = 1e18;
		for(int i = 1;i <= len_v[my_tmp_x];i++){
			for(int j = 1;j <= len_v[my_tmp_y];j++){
				my_part_answ = min(my_part_answ,t[my_tmp_x][i] + t[my_tmp_y][j] + tmp[v[my_tmp_x][i]][v[my_tmp_y][j]]);
			}
		}
		cout << my_part_answ + a[my_tmp_x] + a[my_tmp_y] << '\n';
	}
}
