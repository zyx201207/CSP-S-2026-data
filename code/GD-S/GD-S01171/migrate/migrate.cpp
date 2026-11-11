#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+4;
const int M=504;
const ll inf=1e9;
ll c,t,n,d,ans,x[N],f[M][M];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c>=11&&c<=12){
			ll cnt=0;
			for(int i=2;i<=n;i++){
				if(x[i]-x[1]<=d){
					cnt++;
				}else{
					break;
				}
			}
			if(cnt<=1){
				cout<<"0\n";
			}else{
				cout<<max(0ll,n-(cnt<<1)+1)<<'\n';
			}
		}else if(c>=13&&c<=14){
			ans=0;
			for(int i=1;i<=n;i++){
				ll now=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
				if(now-i<2){
					continue;
				}
				ll t1=upper_bound(x+1,x+n+1,x[now-1]+d)-x-1,t2=0;
				if(now-i>2){
					t2=upper_bound(x+1,x+n+1,x[now-2]+d)-x-1;
				}
				ans+=t1-t2;
			}
			cout<<ans<<'\n';
		}else{
			ans=0;
			for(int i=n-1;i>=1;i--){
				for(int j=i+1;j<=n;j++){
					ll now=x[i],cnt=0;
					for(int k=i;k<=j;k++){
						if(now<x[k]){
							cnt++;
							now=x[k-1]+d;
						}
						if(now<x[k]){
							cnt+=inf;
						}
						f[i][k]=cnt;
					}
					for(int k=i;k<=j;k++){
						now=cnt=0;
						for(int l=k+1;l<=n;l++){
							if(x[l]-x[k]<=d){
								if(!cnt){
									cnt=f[l][j];
									now++;
								}else if(cnt==f[l][j]){
									now++;
								}
							}else{
								break;
							}
						}
					}
					if(now==2){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
SNOWGRAVE
*/
