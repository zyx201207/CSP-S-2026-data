#include<bits/stdc++.h>
using namespace std;
#define int long long
int _,__,n,d,ans,a[2000006],e[5005][5005],cnt[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>_>>__;
	while(__--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n>5000){
			cout<<"I AK IOI!!!";
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) e[i][j]=1e9,cnt[i][j]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) e[i][j]=e[j][i]=1,cnt[i][j]=cnt[j][i]=1;
			}
		}
		for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
			if(e[i][j]>e[i][k]+e[k][j]){
				e[i][j]=e[i][k]+e[k][j];
				cnt[i][j]=cnt[i][k]*cnt[k][j];
			}
			else if(e[i][j]==e[i][k]+e[k][j]){
				cnt[i][j]+=cnt[i][k]*cnt[k][j];
			}
		}
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(cnt[i][j]==2) ans++;
		cout<<ans<<endl;
	}
	return 0;
}//migrate 24pts
