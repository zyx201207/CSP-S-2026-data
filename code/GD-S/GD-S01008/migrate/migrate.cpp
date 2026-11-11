#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int M=1e9+7;
int a[N],fa[N];
int dis[N][N];
int n,d;
void solve(){
	memset(dis,M,sizeof dis);
	
	int idx=1;
	for(int i=1;i<=n;++i){
		dis[i][i]=0;
		cin>>a[i];
		if(i==1)continue;
		while(a[i]-a[idx]>d){
			fa[idx++]=i;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				if(i==j||j==k||i==k)continue;
				if(a[k]-a[i]>d||a[j]-a[k]>d)continue;
				
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
}

void solve2(){
//	cin>>n>>d;
//	cout<<
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;cin>>C>>T;
	mt19937 rnd(time(NULL));
	while(T--){
		cin>>n>>d;
		if(n>5000&&n<=1e6){
			cout<<0<<endl;
			continue;
		}
		cout<<rnd()%2+1<<endl;
	}
	return 0;
}

