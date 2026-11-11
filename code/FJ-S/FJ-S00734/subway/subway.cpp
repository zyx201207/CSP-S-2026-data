#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[5050],t[505][50005];
int k[505];
int a[505][50005];

long long ans;


int solve(int x,int y){
	if(x == y){
		
	}
	vector <int> des;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= k[i];j++){
			if(a[i][j] == y){
				des.push_back(i);
			}
		}
	}
	for(auto u:des){
		for(int j = 1;j <= k[u];j++){
			ans = solve(x,a[u][j]);
		}
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		scanf("%d",w+i);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",k+i);
		for(int j = 1;j <= k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",x,y);
		ans = w[x]+w[y];
		ans += t[1][1];
//		vector<int> des;
//		for(int i = 1;i <= n;i++){
//			for(int j = 1;j <= k[i];j++){
//				if(a[i][j] == y){
//					des.push_back(i);
//				}
//			}
//		}
		cout<<ans<<endl;
	}
	
	return 0;
}
