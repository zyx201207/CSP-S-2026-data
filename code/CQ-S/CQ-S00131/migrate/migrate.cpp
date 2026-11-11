#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,p[2000005],ans,books[2000005];
vector<int> ways[2000005];
void add(int x,int y){
	ways[x].push_back(y);
	ways[y].push_back(x);
}
int dfs(int x,int y,int s){
	if(x == y){
		return s;
	}
	int mmin = INT_MAX;
	for(int i = 0;i < ways[x].size();i++){
		if(!books[ways[x][i]]){
			books[x] = 1;
			mmin = min(mmin,dfs(ways[x][i],y,s + 1));
			books[x] = 0;
		}
	}
	return mmin;
}
int dfsed(int x,int y,int p,int s){
	if(x == y){
		if(p == s){
			return 1;
		}else{
			return 0;
		}
	}
	int ssum = 0;
	for(int i = 0;i < ways[x].size();i++){
		if(!books[ways[x][i]]){
			books[x] = 1;
			ssum += dfsed(ways[x][i],y,p + 1,s);
			books[x] = 0;
		}
	}
	return ssum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> p[i];
		}
		memset(ways,{},sizeof(ways));
		ans = 0;
		for(int i = 2;i <= n;i++){
			for(int j = i - 1;j >= 1;j--){
				if(p[i] - p[j] > d){
					break;
				}
				add(i,j);
			}
		}
		for(int i = 1;i < n;i++){
			for(int j = i + 1;j <= n;j++){
				memset(books,0,sizeof(books));
				int mmin = dfs(i,j,0);
				memset(books,0,sizeof(books));
				int ssum = dfsed(i,j,0,mmin);
				if(ssum == 2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
