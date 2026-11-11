#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2e5+10;
const int LOG=200;
int n, m;
int nodecnt[LOG];
bool st[MAX_N][LOG];
bool vis[MAX_N];
void find(long long a, int x){
	int p=log2(a);
	for(int i=p;i>=0;i--){
		if((a>>i)&1){
			nodecnt[i]++;
			st[x][i]=true;
		}
	}
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	long long maxn=-1;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		maxn=max(maxn, a);
		find(a, i);
	}
	long long res=0;
	for(int i=log2(maxn);i>=0;i--){
		if(nodecnt[i]>=m){
			res+=(1LL<<i);
			for(int j=1;j<=n;j++){
				if(st[j][i]==false&&vis[j]!=true){
					for(int k=LOG-1;k>=0;k--){
						if(st[j][k]==true){
							nodecnt[k]--;
						}
					}
					vis[j]=true;
				}
			}
		}
	}
	cout<<res<<'\n';
	return 0;
}
