#include<bits/stdc++.h>
using namespace std;
int c,T,n,d,a[1000001],sum;
void dfs(int pos,int ed,int num,int t){
//	printf("%d %d %d %d\n",pos,ed,num,t);
	if(pos>ed)return;
	if(pos==ed&&num==t){
		sum++;
		return;
	}
	for(int i=d;i>=1;i--)dfs(pos+i,ed,num+1,t);
}
bool check(int l,int r){
	sum=0;
	int t=(a[r]-a[l])/d+((a[r]-a[l])%d>0);
	dfs(a[l],a[r],0,t);
	return sum==2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=4;i<=n;i++){
			for(int r=i;r<=n;r++){
				int l=r-i+1;
				if(check(l,r))ans++;
		//		printf("%d %d %d\n",l,r,ans);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
