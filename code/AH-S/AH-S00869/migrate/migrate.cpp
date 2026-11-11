#include<bits/stdc++.h>
#define ll long long
#define du double 
using namespace std;
const int M=5005;//最大值 
ll a[5005];
bool dp[5005][5005];
void dfs(int idx,int ans,int n){
	if(idx==n){
		
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		ll d;
		cin>>n>>d;
		int cha[M],pd=1;
		int x,y,c1,c2;
		cin>>x;
		for(int i=2;i<=n;++i){
			cin>>y;
			c2=y-x;
			x=y;c1=c2;
			if(i>=3&&c1!=c2)pd=0;
		}
		if(pd==1){//等差数列 
			int ca=c1;
			ll f=d/ca+1;
			if(d<2*ca||d>=ca*n)cout<<0<<endl;
			else cout<<n-f<<endl;
		}else{
			dfs(1,0,n);
		}
	}
	return 0;
}
