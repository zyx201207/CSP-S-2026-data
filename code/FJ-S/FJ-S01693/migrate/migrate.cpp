#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N],nxt[N],pre[N],cnt1[2][N],cnt2[2][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cnt1[0][i]=0;
			cnt1[1][i]=0;
			cnt2[0][i]=0;
			cnt2[1][i]=0;
		}
		int hh=1;
		for(int i=1;i<=n;i++){
			while(hh+1<=n&&a[hh+1]-a[i]<=d){
				hh++;
			}
			nxt[i]=hh;
		}
		hh=n;
		for(int i=n;i>=1;i--){
			while(hh-1>=1&&a[i]-a[hh-1]<=d){
				hh--;
			}
			pre[i]=hh;
		}
		for(int i=1;i<=n;i++){
			if(nxt[i]!=i){
				if(pre[nxt[i]]==i){
					cnt1[1][nxt[i]]+=cnt1[0][i];
					cnt1[1][nxt[i]]+=cnt1[1][i];
				}
				cnt1[0][nxt[i]]++;
			}
		}
		for(int i=n;i>=1;i--){
			if(pre[i]!=i){
				if(nxt[pre[i]]==i){
					cnt2[1][pre[i]]+=cnt2[0][i];
					cnt2[1][pre[i]]+=cnt2[1][i];
				}
				cnt2[0][pre[i]]++;
			}
		}
		long long ans=0;
		for(int i=1;i<n;i++){
			long long X=cnt1[0][i+1],Y=cnt2[0][i];
			if(nxt[i]==i+1) X--;
			if(pre[i+1]==i) Y--;
			if(nxt[i+1]!=i+1&&pre[nxt[i+1]]==i){
				Y+=cnt2[0][nxt[i+1]];
				Y+=cnt2[1][nxt[i+1]];
			}
			if(pre[i]!=i&&nxt[pre[i]]==i+1){
				X+=cnt1[0][pre[i]];
				X+=cnt1[1][pre[i]];
			}
			ans+=X*Y;
		}
		cout<<ans<<'\n';
	}
}
