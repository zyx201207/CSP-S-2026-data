#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t,n,cnt,ans,pre[N],suf[N];
long long x[N],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(pre,0,sizeof(pre));
		memset(suf,0,sizeof(suf));
		cin>>n>>d;
		ans=cnt=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			pre[i]=1;
			if(i>1&&x[i]-x[i-1]<=d){
				pre[i]=pre[i-1]+1;
			}
			if(i>2&&x[i]-x[i-2]<=d){
				pre[i]=1;
			}
		}
		for(int i=n;i>=1;i--){
			suf[i]=1;
			if(i<n&&x[i+1]-x[i]<=d){
				suf[i]=suf[i+1]+1;
			}
			if(i<n-1&&x[i+2]-x[i]<=d){
				suf[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			cnt++;
			if(i>1&&x[i]-x[i-1]>d){
				cnt=1;
			}
			if(i>2&&x[i]-x[i-2]>d){
				cnt=1;
			}
			if(cnt>=4&&x[i]-x[i-3]>d){
				ans+=(pre[i-3]*suf[i]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
