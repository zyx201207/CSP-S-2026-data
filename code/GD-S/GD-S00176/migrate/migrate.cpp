#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,t,n,d;
int en,mi,s,ans;
ll a[N];

inline int getmin(int i,int j){
	int res=0;
	int p=i;
	while(p<j){
		res++;
		int t=upper_bound(a+1,a+n+1,a[p]+d)-a-1;
		if(p==t){
			res=-1;
			break;
		}
		p=t;
	}
	return res;
}
inline void dfs(int p,int st){
	if(st>=mi){
		if(p==en)
			s++;
		return ;
	}
	int to=p+1;
	while(to<=en){
		if(a[p]+d>=a[to])
			dfs(to,st+1);
		else
			break;
		to++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				mi=getmin(i,j);
				if(mi<=1)
					continue;
				s=0,en=j;
				dfs(i,0ll);
				if(s==2)
					ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
