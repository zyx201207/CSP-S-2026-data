#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int c,n,m,d,q;
int a[N][N],t[N][N],w[N],k[N];
int sum = 0,ans = 0;
void dfs(int x,int y){
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			//sort(t + 1,t + 1 + m);
		}
	}
	return 0;
}
