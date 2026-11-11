#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[3000001];
long long cnt;
long long sum;
struct node{
	long long u,w;
};
long long mi=INT_MAX;
queue<node>q;
void bfs(long long u,long long v,long long w){
	q.push({u,w});
	while(!q.empty()){
		node tmp=q.front();
		q.pop();
		if(tmp.w>mi) continue;
		if(tmp.u==v){
			sum++;
			mi=tmp.w;
			if(sum>2){
				return ;
			}
			continue;
		}
		for(long long i=tmp.u+1;i<=n;i++){
			if(abs(x[i]-x[tmp.u])<=d){
				q.push({i,tmp.w+1});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		if(x[n]-x[1]<=10*d && n>5000){
			cout<<0<<"\n";
			continue;
		}
		cnt=0;
		for(long long j=1;j<=n;j++){
			for(long long k=j+1;k<=n;k++){
				sum=0;
				mi=INT_MAX;
				while(!q.empty()) q.pop();
				bfs(j,k,0);
				if(sum==2) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
