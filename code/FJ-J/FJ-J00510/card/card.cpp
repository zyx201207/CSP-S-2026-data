#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], s[M], num[N], fa[N];
vector<int> b[M];
void _card(){
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		if(num[a[i]]){
			fa[i] = num[a[i]];
			continue;
		}
		for(int j = n; j > i; j--){
			if(a[i] == a[j]){
				fa[i] = j;
				break;
			}
		}
		num[a[i]] = fa[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			s[a[j]]++;
			j = fa[j];
		}
	}
	for(int i = 1; i <= m; i++){
		printf("%d ", s[i]);
	}
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d", &n, &m);
	if(m <= 2){
		_card();
		return 0;
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		b[a[i]].push_back(i);
		num[i] = b[a[i]].size();
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int flag = 0, now = a[j];
			int l = b[now].size();
			if(l > num[j]){
				flag = b[now][num[j]];
			}
			if(flag == 0){
				s[now]++;
			}else{
				j = flag - 1;
				continue;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		printf("%d ", s[i]);
	}
	return 0;
}

