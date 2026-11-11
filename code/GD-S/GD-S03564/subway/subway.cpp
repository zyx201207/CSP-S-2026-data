#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=510,M=2e4+10;
long long INF=1e18;
int c;
ll n,m,d,p;
ll a[N][M],w[N],s[N],dis[N][M],b[N],t[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(s,INF,sizeof(s));
	memset(dis,INF,sizeof(dis));
	cin>>c>>n>>m>>d>>p;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;cin>>k;
		for(ll j=1;j<=k;j++){
			cin>>b[j]>>t[j];
			if(j==1){
				s[b[j]]+=t[j];
			}
			else{
				s[b[j]]+=t[j];
				dis[b[j-1]][b[j]]=dis[b[j]][b[j-1]]=s[b[j-1]];
				s[b[j-1]]=t[j-1];
			}
		}
		memset(b,0,sizeof(b));
		memset(t,0,sizeof(t));
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j && j!=k && i!=k){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	while(p--){
		ll s,t;
		cin>>s>>t;
		cout<<dis[s][t]+w[s]+w[t]<<endl;
	}
	return 0;
}
