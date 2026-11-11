#include<bits/stdc++.h>
using namespace std;
const long long LIMIT = 1e5 + 10;
long long n, m, path_length, counter, same, biggest_same, dangqian, change, same_number, dangqian_number;
long long path[LIMIT], power[LIMIT], add_power[LIMIT], station[LIMIT];
bool used[LIMIT], is_jian = true;
void dfs(){
	if(path_length == m){
//		cout << 1;
//		for(int i = 1; i <= m; i++){
//			printf("%lld ", path[i]);
//		}
//		printf("\n");
		for(int i = 1; i <= n; i++){
			add_power[i] = power[i];
		}
		for(int i = 1; i <= m; i++){
			add_power[station[i]]++;
		}
//		for(int i = 1; i <= m; i++){
//			printf("%lld ", add_power[i]);
//		}
//		printf("\n");
		dangqian = 1;
		same_number = 0;
		sort(add_power + 1, add_power + m + 1);
//		for(int i = 1; i <= m; i++){
//			printf("%lld ", add_power[i]);
//		}
//		printf("\n");
		for(int i = 2; i <= m; i++){
			if(add_power[i] == add_power[i - 1])	dangqian++;
			else break;
		}
		biggest_same = max(dangqian, biggest_same);
		
		return;
	}
//		printf("\n");
	
	for(int i = 1; i <= n; i++){
		path[++path_length] = power[i];
		station[path_length] = i;
		used[path_length] = true;
//		printf("%lld\n", path_length);
//		cout << 1;
//		add_power[path_length] = path[path_length];
		dfs();
		used[path_length] = false;
		--path_length;
	}
	
	return;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%lld", &n);
	scanf("%lld", &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &power[i]);
		add_power[i] = power[i];
//		if(add_power[i] )
	}
//	for(int i = 1; i <= n; i++){
//		cout << power[i] << ' ';
//	}
	for(int i = 1; i <= n; i++){
		path[++path_length] = power[i];
		used[path_length] = true;
		station[path_length] = i;
//		add_power[path_length] = path[path_length];
		dfs();
		used[path_length] = false;
		--path_length;
	}
	printf("%lld\n", biggest_same);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
