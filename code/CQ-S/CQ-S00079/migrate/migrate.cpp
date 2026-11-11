#include<bits/stdc++.h>
using namespace std;
int n,t,c,d;
int a[100001],dp[100001];//走到坐标为j时的最少所需的 
/*void dfs(int step,int x,int ci,int bu){
	if(x==a[n]){
		if(step == ci);{
			
		}
		return ;
	}
	for(int i = 1;i<=bu;i++){	
		 vis[x]++;
		 dfs
	}
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		int ma = abs(a[n]-a[1])/d+1;
		cout << ma<<endl;
	}
	return 0;
}

