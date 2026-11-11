#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+7;
ll d,x[maxn];
int num[maxn],n,t,ans,c;
void dfs(int u,int cnt){
	if(cnt==2){
		num[u]++;
		return;
	}
	for(int i=u+1;x[i]-x[u]<=d&&i<=n;i++){
		dfs(i,cnt+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int v=1;v<=t;v++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		dfs(1,0);
		for(int i=1;i<=n;i++){
			if(num[i]==2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
