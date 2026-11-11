#include<bits/stdc++.h>
using namespace std;
int n,m,maxn = -1;
int a[500005];

int count(int cc,int b[]){
	int cnt = 0;
	for(int i = 0;i < n;i++){
		if(b[i] == cc){
			cnt ++;
		}
	}return cnt;
}
void dfs(int x,int tl,int b[]){
	if(x > n || m <= 0){
		return ;
	}int x1 = count(b[x-1],b);
	if(x1 >= maxn){
		maxn = x1;
	}for(int i  = 0;i <= tl;i++){
		b[x] += i;
		dfs(x+1,m-i,b);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;int b[500005];
	for(int i = 0 ;i < n;i++){
		cin >> a[i];
		b[i] = a[i];
	}
	for(int i = 1;i <= m;i++){
		dfs(1,i,b);
	} 
	cout << maxn;
	return 0;
}
