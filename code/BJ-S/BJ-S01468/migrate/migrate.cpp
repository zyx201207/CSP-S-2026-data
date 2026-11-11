#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,d;
int a[2*1145141];
int dis[2*1141541];
int cnt[2*1141541];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	
	while(T--){
		int ans = 0;
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		a[0] = LONG_LONG_MIN;
		a[n+1] = LONG_LONG_MAX;
		int cen = 1;
		for(cen = 1;cen <= n;cen++){
			for(int i = 0;i<=cen+1;i++){
				dis[i] = LONG_LONG_MAX/1145;
			}	
			dis[cen] = 0;
			int lpos = cen,lx = a[lpos];
			for(lpos = cen-1;lpos > 0;lpos--){
				if(lx-a[lpos] > d){
					lx = a[lpos+1];
					dis[lpos] = 1;
				}else if(a[lpos+1]-a[lpos] <= d){
					dis[lpos] = 0;
				}else{
					break;
				}
			}
			if(dis[cen]-dis[cen-1] <= d){
				dis[cen-1]++;
			}
			//for(rpos = cen;rpos <= n;rpos++){
				//if(a[rpos]-rx > d){
					//rx = a[rpos-1];
					//dis[rpos]++;
				//}
			//}
			for(int i = cen-1;i>=1;i--){
				if(dis[i] > 2*1145141)break;
				dis[i] += dis[i+1];
			}
			//for(int i = cen+1;i<=n;i++){
				//dis[i] += dis[i-1];
			//}
			//cout<<'\n';
			//for(int i = 1;i<=n;i++){
			//	cout<<dis[i]<<' ';
			//}
			//cout<<'\n';
			cnt[cen] = 1;
			int ll,lr = cen,ldiv;
			for(ll = cen-1;ll >= 1;ll--){
				if(dis[ll] > 2*1145141)break;
				while(a[lr]-a[ll] > d){
					lr--;
				}
				if(dis[ll] != dis[ll+1]){
					ldiv = ll+1;
				}
				if(ldiv == lr){
					cnt[ll] = min(cnt[ldiv],3ll);
				}else if(lr == ldiv+1){
					cnt[ll] = min(cnt[ldiv]+cnt[ldiv+1],3ll);
				}else{
					cnt[ll] = 3ll;
				}
				//cout<<ll<<' '<<lr<<' '<<ldiv<<' '<<cnt[ll]<<'|';
			}
			
			for(int i = 1;i<=cen;i++){
				if(cnt[i] == 2){
					ans++;
				}
				cnt[i] = 0;
			}	
		}
		cout<<ans<<'\n';
	}
	return 0;
}
