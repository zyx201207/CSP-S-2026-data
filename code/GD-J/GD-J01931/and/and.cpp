#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],maxx,f[25][25];
deque<int>q;
bool dis[N];
void dfs(int cnt){
	if(cnt==m){
		int sum=q.front();
		q.push_back(q.front());
		q.pop_front();
		for(int i=2;i<=q.size();i++)sum=(sum&q.front()),q.push_back(q.front()),q.pop_front();
		maxx=max(sum,maxx);
		return;
	}
	for(int i=1;i<=n;i++)
		if(dis[a[i]]==0){
			dis[a[i]]=1;
			q.push_back(a[i]);
			dfs(cnt+1);
			dis[a[i]]=0;
			q.pop_back();
		}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=2000){
		if(m==1){
			int maxx=0;
			for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
			cout<<maxx;
			return 0;
		}
		else if(m==2){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					f[i][j]=(a[i]&a[j]),maxx=max(maxx,f[i][j]);
			cout<<maxx;
			return 0;
		}
		else if(n==m){
			int sum=a[1];
			for(int i=2;i<=n;i++)sum=(sum&a[i]);
			cout<<sum;
			return 0;
		}
	}
	else if(n<=20){
		dfs(1);
		cout<<maxx;
		return 0;
	}
	return 0;
}
