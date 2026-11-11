#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long n,m,T,c,ans,num,minn=N;
long long a[N],b[N];
bool vis[N];
void dfs(long long p,long long q,long long x){
	if(b[p]+p==q) return;
	for(int i=1;i<=x;i++){
		num++;
		dfs(p,q,b[x+i]);
		minn=min(minn,num);
	}
	return;
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		long long ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=m){
					b[a[i]]++;
				}
				else break;
			}
		}
		for(int i=1;i<=n-3;i++){
			num=0;
			long long tmp=0;
			for(int j=i+3;j<=n;j++){
				dfs(i,j,b[i]);
			}
		}
		cout<<minn<<'\n';
	}
	return 0;
} 
