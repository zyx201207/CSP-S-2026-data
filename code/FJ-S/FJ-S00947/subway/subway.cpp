#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=114514;
int c,n,m,d,q,x,y,pp1[MAXN];
int t1[MAXN],t2[510][MAXN];
int di[510][MAXN];

void solve(){
	int s=0;
	scanf("%lld%lld",&x,&y);
	for(int i=1;i<=n;i++){
		bool fx=0,fy=0;
		int ans=0; 
		for(int j=1;j<=pp1[i];j++){
			if(di[i][j]==x&&(!fx)){
				ans+=t2[i][j];
				fx=1;
			}  
			if(di[i][j]==y&&(!fy)){
				ans+=t2[i][j];
				fy=1;
			}  
		}
		if(fx&&fy){
			ans+=(t1[x]+t1[y]);
			s=max(s,ans);
		}
	}
	if(!s){
		int iix,jjx,iiy,jjy;
		for(int i=1;i<=n;i++){
		bool fx=0,fy=0;
		int ans=0; 
		for(int j=1;j<=pp1[i];j++){
			if(di[i][j]==x&&(!fx)){
				iix=i,jjx=j;
				fx=1;
			}  
			if(di[i][j]==y&&(!fy)){
				iiy=i,jjy=j;
				fy=1;
			}  
		}
	}
	for(int i=1;i<=pp1[iix];i++){
		for(int j=1;j<=pp1[iiy];j++){
			if(di[iix][i]==di[iiy][j]){
				s+=(t1[x]+t1[y]+t2[iix][jjx]+t2[iiy][jjy]+t2[iix][i]+t2[iiy][j]);
				break;
			}
		}
	}
	}
	printf("%lld\n",s);
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)  scanf("%lld",&t1[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&pp1[i]);
		for(int j=1;j<=pp1[i];j++){
			scanf("%lld%lld",&di[i][j],&t2[i][j]);
		}
	}
	while(q--){
		solve();
	}
	return 0;
}
