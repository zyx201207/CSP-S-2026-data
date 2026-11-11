#include <bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int a[N];
int b[N];
bool f[N];
int dfs(int x,int y,int deep,int d){
	if(y==x){
		return deep;
	}
	for(int i=x;i<=y;++i){
		if(abs(a[x]-a[y])<=d && !f[x]){
			f[i]=true;
			dfs(i,y,deep+1,d);
			f[i]=false;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(b,0,sizeof(b));
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				b[dfs(i,j,0,d)]++;
			}
		}
		int sum=0;
		for(int i=1;i<=n;++i){
			if(b[i]==2){
				sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
