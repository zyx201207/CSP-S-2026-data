#include <bits/stdc++.h>
#define int long long
using namespace std;

int t,n,d,loc[1000005],dis,plan,len=-1,length[1000005],ans;

int dist(int u,int v){
	dis=loc[v]-loc[u];
	return dis;
}
void dfs(int u,int v){
	len++;
	if(u==v && len<length[v]) {
		plan=0;length[v]=len;
	}
	if(u==v && len==length[v]) {
		plan++;
		return;
	}
	for(int p=u+1;p<=v && dist(u,p)<=d;p++){
		dfs(p,v);
	}
}



signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t >> t;
	for(int loop=0;loop<t;loop++){
		cin >> n >> d;
		for(int i=0;i<n;i++){
			cin >> loc[i];
		}
		
	for(int u=0;u<n;u++){
		for(int v=u+2;v<n;v++){
			length[v]=1000005;
			dfs(u,v);
			if (plan==2) ans++;
			memset(length,0,sizeof(length));
			plan=0;
		}
	}
		cout << ans;
	}
}
