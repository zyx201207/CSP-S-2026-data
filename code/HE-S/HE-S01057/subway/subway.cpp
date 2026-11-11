#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,k[1000001],o;
ll w[10000001],t[5001][5001],a[5001][5001],ma[5001][5001],minsum=INT_MAX,vis[1000100],v[5001][5001];
void maps(ll x,ll end,ll step,ll sum){
	if(x==end){
		minsum=min(minsum,sum+v[o][x]);
		return;
	}
	if(step==1){
		for(ll i=1;i<=m;i++){
			if(ma[x][i]!=0){
				o=ma[x][i];
				vis[i]=1;
				maps(i,end,step+1,sum+v[o][x]);
				vis[i]=0;
			}
		}
	}else{
		for(ll i=1;i<=m;i++){
			if(ma[x][i]!=0 && ma[x][i]!=o && vis[i]==0){
				vis[i]=1;
				ll o1=o;
				o=ma[x][i];
				maps(i,end,step+1,sum+v[o1][x]+v[o][x]);
				vis[i]=0;
			}else if(ma[x][i]!=0 && ma[x][i]==o && vis[i]==0){
				vis[i]=1;
				maps(i,end,step+1,sum);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			v[i][a[i][j]]=t[i][j];
			if(j!=1){
				ma[a[i][j-1]][a[i][j]]=i;
				ma[a[i][j]][a[i][j-1]]=i;
			} 
		}
	}
	ll l,r;
	for(ll i=1;i<=q;i++){
		memset(vis,0,sizeof vis);
		cin>>l>>r;
		minsum=LONG_MAX;
		vis[l]=1;
		maps(l,r,1,w[l]+w[r]);
		cout<<minsum<<endl;
	}
	
	return 0;
}

