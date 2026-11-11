#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6+5;
int n,d,ans,minn=2e9;
int x[MAXN];
bool flag[MAXN];
void dfs(int a,int b,int sum){
	if(a==b){
		if(minn==sum)ans++;
		minn = min(minn,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		int lo=0;
		if(x[a]>x[i])	lo=x[a]-x[i];
		else lo=x[i]-x[a];
		if(lo<=d&&!x[i]){
			flag[x[i]]=true;
			dfs(x[i],b,sum+lo);
			flag[x[i]]=false;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		ans=0;
		memset(flag,false,sizeof flag);
		for(int start=1;start<=n-1;start++){
			for(int end=2;end<=n;end++){
				flag[start] = true;
				dfs(start,end,0);
			}
		}
		cout << ans << "\n";
		memset(x,0,sizeof x);
	}
	return 0;
}

