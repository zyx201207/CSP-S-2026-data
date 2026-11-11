/*【数据范围】
对于所有测试数据，均有：
0 ≤ c ≤ 25，1 ≤ n ≤ 500，1 ≤ m ≤k ≤ 5*105，1 ≤ d ≤ 20，1 ≤ q ≤ 105；
对于所有v (1 ≤ v ≤ m)，均有1 ≤ w ≤ 109；*/
#include<bits/stdc++.h>
using namespace std;
int n,m,gk,gk1=0,q,qus;
long long ans[500001];
int a,b;

int w[500001];//地铁口到站台的距离
int h[500001][21]/*每个站所联通路线*/,t[500001][21],num[500001],num2[301],connection[301][400001];
void dfs(int s){
	for(int i=1;i<=num[s];i++){
			for(int j=1;j<=num2[i];j++){
			if(connection[i][j]!=s){
				if(ans[connection[i][j]]==0||ans[connection[i][j]]>ans[s]+t[i][connection[i][j]]+t[i][s]){
					ans[connection[i][j]]=ans[s]+t[i][connection[i][j]]+t[i][s];
					dfs(connection[i][j]);
				}
			}
		}
		
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>gk>>n>>m>>gk>>q;
	
	for(int i=1;i<=m;i++){
		num[i]=1;
	} 
	for(int i=1;i<=n;i++){
		num2[i]=1;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>gk;
		for(int j=1;j<=gk;j++){
			cin>>a;
			h[a][num[a]]=i;
			connection[i][num2[i]]=a;
			num2[i]++;
			cin>>b;
			t[i][a]=b;
			num[a]++;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>gk;
		cin>>qus;
		if(gk==gk1){
			cout<<ans[qus];
		}
		else{
			gk1=gk;
			for(int j=1;j<=m;j++){
				ans[j]=0;
			}
			ans[gk]=w[gk];
			dfs(gk);
			cout<<ans[qus]+w[qus]<<endl;
		}
		
	}
}
