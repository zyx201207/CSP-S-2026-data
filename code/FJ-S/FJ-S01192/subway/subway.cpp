#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y;	
long long w[500011];
long long pq[2011][20011];
long long cnt[500011];
bool b[2011][20011];
void dfs(int a){
	if(a==y){
		return;
	}
	for(int i=1;i<=20011;i++){
		if(b[i][a]==0&&pq[i][a]!=0){
			b[i][a]=1;
			cnt[i]=min(cnt[a]+pq[i][a],cnt[i]);
			dfs(i);
		}
		if(b[a][i]==0&&pq[a][i]!=0){
			b[a][i]=1;
			cnt[i]=min(cnt[a]+pq[i][a],cnt[i]);
			dfs(i);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k/2;j++){
			int a,t;
			cin>>a>>t;
			pq[k][a]=t;
			pq[a][k]=t;
		}
	}
	for(int i=1;i<=500011;i++){
		cnt[i]=50011;
	}
	while(q--){ 
		int ans=0;
		cnt[x]=0;
		cin>>x>>y;
		cout<<cnt[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
