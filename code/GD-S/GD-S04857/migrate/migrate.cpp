#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
vector<int> p;
ll a[N];
int d,n;
ll num,ans,minn=1e18;//cnt步数，num路径数，ans双径岛屿对数 
void dfs(int x,int y,ll cnt){
	if(x==y){
		minn=min(cnt,minn);
		num++;
		p[num]=cnt;
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d){
			dfs(i,y,cnt+1);
		}
		else return;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		p.clear();
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				num=0,minn=1e18;
				dfs(i,j,0);
				int sum=0;
				for(int k=1;k<=num;k++){
					if(p[i]==minn) sum++;
				}
				if(sum==2) ans++;
			}
		}		
		cout<<ans<<'\n';
	}
	return 0;
} 
