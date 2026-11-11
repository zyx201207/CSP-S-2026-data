#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long w=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		w=w*10+c-'0';c=getchar();
	}
	return w*f;
}
const int H=2e6+10;
long long n,d,h[H],c,t;
pair<long long,long long>dis[600][600];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	c=read();t=read();
	while(t--){
	n=read();d=read();
	for(int i=1;i<=n;i++){
		memset(dis[i],0x3f,8*(n+1));
	}
	for(int i=1;i<=n;i++)h[i]=read();
	for(int i=1;i<=n;i++){
		for(int p=1;p<=n;p++){
			if(abs(h[i]-h[p])<=d)
				dis[i][p]={1,1};
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int p=1;p<=n;p++){
			long long u=dis[i][k].first+dis[k][p].first;
			if(u<dis[i][p].first){
				dis[i][p]={u,dis[i][k].second*dis[k][p].second}; 
			}
			else if(u==dis[i][p].first){
				dis[i][p].second+=dis[i][k].second*dis[k][p].second;
			}
		}
	}}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int p=1;p<i;p++){
			if(dis[i][p].second==2)++ans;
		}
	}
	cout<<ans<<'\n';
	}
	return 0;
} 
