#include <bits/stdc++.h>
using namespace std;
int c,t,n;long long x[2000005],d,cnt=0,minn=10000000,ans=0;bool flag;
void dfs(int nw,int end,int moves){
	if (moves>minn||flag) return ;
	if (nw==end){
		if (moves<minn){
			minn=moves;
			cnt=1;
		}else if (moves==minn){
			cnt++;
		}
		flag=(cnt>2);
		return ;
	}
	if (nw>end) return ;
	for (int i=1;x[nw+i]-x[nw]<=d&&nw+i<=n;i++){
		dfs(nw+i,end,moves+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		ans=0;
		for (int i=1;i<=n;i++) cin>>x[i];
		for (int i=1;i<=n;i++){
			for (int j=i+3;j<=n;j++){
				cnt=0;
				minn=10000000;
				flag=0;
				dfs(i,j,0);
				if (cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
