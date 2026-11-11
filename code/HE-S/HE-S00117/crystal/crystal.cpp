#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int MAXN=500005;
int n,ans;
ll m,a[MAXN],d,dL;
bool bo=1;
void dfs(int u,int based,ll cost){
	if(u>=n){
		ans=max(ans,u);
		return;
	}if(cost>=m){
		int cnt=u;
		for(int i=u+1;i<=n;i++){
			if(a[i]==based){
				cnt++;
			}else{
				break;
			}
		}ans=max(ans,cnt);
		return;
	}if(a[u]>=based){
		ans=max(ans,u);
		return;
	}dfs(u+1,based,cost-a[u]+based);
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(bo){
			dL=d;
			d=a[i]-a[i-1];
		}if(i<=2){
			continue;
		}if(d!=dL){
			bo=0;
		}
	}sort(a+1,a+n+1);
	if(bo){
		ll sum=0,i;
		int cnt=0;
		for(i=d;;i+=d){
			sum+=i;
			cnt++;
			if(sum>m||cnt>=n){
				break;
			}
		}ans=cnt;
	}else if(!m){
		int cnt=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				cnt++;
			}else{
				ans=max(ans,cnt);
				cnt=1;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			dfs(1,a[i],0);
		}
	}cout<<ans<<'\n';
	return 0;
}
