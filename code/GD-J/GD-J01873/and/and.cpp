#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],cnt,maxn,ans;
bool vis[N][35],flag[N];
bool cmp(int x,int y){
	return x>y;
}
int w(int x){
	int res=0;
	while(x)res++,x>>=1;
	return res;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],maxn=max(maxn,w(a[i])),flag[i]=1;
	sort(a+1,a+1+n,cmp);
	for(int i=0;i<=maxn;i++)
	for(int j=1;j<=n;j++)if(a[j]&(1<<i))vis[j][i]=1;
	for(int i=maxn;i>=0;i--){
		int cnt=0;
		vector<int>x;
		for(int j=1;j<=n;j++){
			if(!flag[j])continue;
			if(!vis[j][i]){
				x.push_back(j);
				continue;
			}
			cnt++;
		}
		if(cnt>=m){
			ans=ans+(1<<i);
			for(auto num:x)flag[num]=0;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
