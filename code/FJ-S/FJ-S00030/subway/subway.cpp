#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m,c,q,d,w[500005],ans=2147483647;
int mp[5010][5010]={0};
int zt[5010][5010]={0};
void solve(int l,int r,int t){
	if(l==r){
		ans=min(ans,t+w[r]);
	}
	for(int i=0;i<n;i++){
		if(zt[l][i]!=0&&mp[i][1]!=l){
			solve(mp[i][1],r,t+zt[l][i]+zt[mp[i][1]][i]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			mp[i][j]=a;
			zt[a][i]=t;
		}
	}
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		//ans=w[l];
		solve(l,r,w[l]);
		cout<<ans<<endl;
	}
	return 0;
}
