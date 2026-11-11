//GZ-S00311 ÒóÕğ²© ×ñÒåËÄÖĞ 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,T;
const int N=5e3+5;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,ans=0;
		ll d;
		cin>>n>>d;
	    ll a[n+1];
	    for(int i=1;i<=n;i++)cin>>a[i];
	    for(int i=1;i<n;i++){
	    	bool vis[n+1]={false};
	    	int cnt[n+1],num[n+1];
	    	cnt[i]=0;
	    	queue<int> q;
	    	q.push(i);
	    	while(!q.empty()){
	    		int u=q.front();
				q.pop();
				for(int j=u+1;j<=n;j++){
					if(a[j]-a[u]>d)break;
					if(!vis[j])vis[j]=true,cnt[j]=cnt[u]+1,q.push(j);
					else if(cnt[j]==cnt[u]+1)++num[j];
				}
			}
			for(int j=i+1;j<=n;j++)if(num[j]==2)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
