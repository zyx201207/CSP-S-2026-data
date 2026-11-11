#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],maxr,maxr2=-1,maxr3,ans=-27;

void dfs(int i,int sum,int maxv){
	if(sum==m){
		ans=max(ans,maxv);
		return ;
	}
	if(i==n){
		if(sum==m) ans=max(ans,maxv);
		return ;
	}
	if(sum+n-i<m) return ;
	int tik=0;
	for(int j=i+1;j<=n;j++){
		dfs(j,sum,maxv);
		if(sum!=0) dfs(j,sum+1,(maxv&a[j]));	
		if(sum==0) dfs(j,sum+1,a[j]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i==1) maxr3=a[1];
		else maxr3=(maxr3&a[i]);
		maxr=max(maxr,a[i]);	
	}
	if(m==1){
		cout << maxr ;
		return 0;
	}
	if(m==n){
		cout << maxr3;
		return 0;
	}
	if(m==2&&n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) if(i!=j){
				maxr2=max(maxr2,(a[i]&a[j]));
			}
		}
		cout << maxr2;
		return 0;
	}
	else dfs(0,0,0);
	cout << ans;
	return 0;
}
