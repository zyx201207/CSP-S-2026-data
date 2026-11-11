#include<bits/stdc++.h>
using namespace std;
int w[500005];
vector<int> a[500005];
vector<int> na[505];
int t[505][500005];
int len[505];
long long dp[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		len[i]=k;
		for(int j=1;j<=k;j++){
			int aij,tij;
			cin>>aij>>tij;
			a[aij].push_back(i);
			na[i].push_back(aij);
			t[i][aij]=tij;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		queue<int> q;
		for(int i=1;i<=n;i++){
			dp[i]=1e18;
		}
		for(int i=0;i<a[x].size();i++){
			q.push(a[x][i]);
			dp[a[x][i]]=t[a[x][i]][x]+w[x];
		}
		while(q.size()){
			int now=q.front();
			q.pop();
			for(int i=0;i<na[now].size();i++){
				if(a[na[now][i]].size()>1){
					for(int j=0;j<a[na[now][i]].size();j++){
						int node=na[now][i];
						int line=a[na[now][i]][j];
						long long temp=dp[now]+t[now][node]+t[line][node];
						if(temp<dp[line]){
							q.push(line);
							dp[line]=temp;
						}
					}
				}
			}
		}
		long long ans=1e18;
		int lastline=0;
		for(int i=0;i<a[y].size();i++){
			if(ans>dp[a[y][i]]){
				ans=dp[a[y][i]];
				lastline=a[y][i];
			}
		}
		cout<<ans+t[lastline][y]+w[y]<<endl;
	}
	return 0;
}
