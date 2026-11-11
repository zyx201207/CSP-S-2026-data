#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,c,T;
long long x[N],lst[N],d,cnt[N],mi[N],ans,thi,jishu;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int now=0,dis=0;
		for(int i=1;i<=n;i++){
			dis+=x[i]-x[i-1];
			while(dis>d){
				now++;
				dis-=x[now]-x[now-1];
			}
			lst[i]=max(1,now);
		}
		for(int s=1;s<=n;s++){
			for(int i=s;i<=n;i++){
				cnt[i]=0;
				mi[i]=1e18;
			}
			mi[s]=0;
			cnt[s]=1;
			for(int e=s+1;e<=n;e++){
				for(int j=max(1ll*s,lst[e]);j<=e;j++){
					if(mi[j]+1==mi[e]){
						cnt[e]+=cnt[j];
					}
					else if(mi[j]+1<mi[e]){
						mi[e]=mi[j]+1;
						cnt[e]=cnt[j];
					}
				}
				if(cnt[e]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
