//GZ-S00263 兴义市弘毅中学 韩愈信
#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[1000005],ans,cnt[1000005],minn[1000005];
void dfs(int step,int len){
	if(len>minn[step]) return;
	cnt[step]++;
	if(step==n) return;
	for(int i=step+1;i<=n&&x[i]-x[step]<=d;i++){
		dfs(i,len+1);
	}
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
    	cin>>n>>d;
    	ans=0;
    	for(int i=1;i<=n;i++){
    		cin>>x[i];
		}
		x[n+1]=2e18+1;
		for(int l=1;l<=n;l++){
			int sum=0,num=0;
			for(int r=l+1;r<=n+1;r++){
				if(sum+x[r]-x[r-1]<=d) {
					sum+=x[r]-x[r-1];
					minn[r]=num+1;	
				}
				else if(x[r]-x[r-1]<=d){
					sum=0;
					num++;
					minn[r]=num+1;
				}else{
					minn[r]=-1;
					break;
				}
			}
			for(int i=l+1;i<=n;i++) cnt[i]=0;
			dfs(l,0);
			cout<<'\n';
			int tmp=0;
			for(int i=l+1;i<=n;i++) {
				tmp+=(cnt[i]==2);
			}
			ans+=tmp;
		}
		cout<<ans<<'\n';
	}
    return 0;
}
