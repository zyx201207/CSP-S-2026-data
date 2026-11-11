#include<bits/stdc++.h>
using namespace std;
long long N[2000005];
int p[2000005];
int p2[2000005];
long long ans;
void solve(){
	ans=0;
	int n;
	long long d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>N[i];
	int cnt3=2;
	p2[1]=1;
	for(int i=1;i<n;i++){
		if(N[i+1]-N[i]>d) p2[cnt3++]=i;
	}
	p2[cnt3++]=n;
	for(int k=1;k<cnt3-1;k++){
		for(int i=p2[k];i<=p2[k+1];i++){
		for(int j=i+3;j<=p2[k+1];j++){
			if(N[j]-N[i]<=d) continue;
			p[1]=i;
			int cnt=2,no=i;
			bool flag=1;
			for(int k=i;k<j;k++){
				if(N[k+1]-N[no]>d){
					p[cnt++]=k;
					no=k;
				}
			}
			p[cnt++]=j;
			if(!flag) continue;
			int po=2;
			int cnt2=1;
			for(int k=i+1;k<j;k++){
				while(k>p[po]) po++;
				if(k==p[po]) continue;
				if(p[po]==j) break;
				if(N[k]-N[p[po-1]]<=d&&N[p[po+1]]-N[k]<=d){
					 cnt2++;
				}
			}
			if(cnt2==2){
				 ans++;
			}
		}
	}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
