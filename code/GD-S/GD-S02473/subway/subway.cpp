#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,a[500030],s[505][505],k,x,y,ans;
int sum[505][505]={0,0};
int solve(int l,int r,int u){
	if(l==r){
		if(ans==-1)
		ans=u;
		else
		ans=min(ans,u);
	}
	for(int i=l+1;i<=r;i++){
		if(s[l][i]!=0){
			sum[l][i]+=s[l][l];
			sum[l][i]+=u;
			sum[l][i]+=s[l][i];
			solve(i,r,sum[l][i]);
		}
	}return 0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int i=1;i<=k;i++){
			
			if(i==1){
				cin>>x;
			cin>>s[x][x];
		}
			else{
				cin>>y;
			cin>>s[x][y];
		}
		}
		
	}while(q--){
		cin>>x>>y;
		ans=-1;
		memset(sum,0,sizeof(sum));
		solve(x,y,0);
		cout<<ans+a[x]+a[y]<<endl;
	}
return 0;
}
