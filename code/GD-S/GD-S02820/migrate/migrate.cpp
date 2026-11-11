#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,st[N],tp,ans,x[N],fl;
void work(){
	cin>>n>>d;ans=0;
	for (int i=1;i<=n;i++){
		cin>>x[i];
	}
	for (int i=1;i<=n;i++){
		tp=0;st[tp]=i;fl=1;
		for (int j=i+1;j<=n;j++){
			if (x[j]-x[j-1]>d) fl=0;
			if (fl==0) continue ;
			if (x[j]-x[st[tp]]>d){
				st[++tp]=j-1;
			}int cnt=0;st[++tp]=j;
			for (int k=1;k<tp;k++){
				if (st[k]-1>st[k-1]){
					if (x[st[k+1]]-x[st[k]-1]<=d){
						cnt++;
						if (k>1&&st[k-1]-1>st[k-2]){
							if (x[st[k]-1]-x[st[k-1]-1]<=d){
								cnt++;//del
							}
						}
					}
				}
				if (st[k]-2>st[k-1]){
					if (x[st[k+1]]-x[st[k]-2]<=d) cnt++;
				}
			}
			//for (int k=0;k<=tp;k++) cout<<st[k]<<" ";
			//cout<<endl;
			tp--;if (cnt==1) ans++;
		}
	}cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;while (t--) work();
	return 0;
}
