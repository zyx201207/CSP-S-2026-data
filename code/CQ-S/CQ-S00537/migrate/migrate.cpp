#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int ID,T,n,nxt[N],pr[N],jl[N],jr[N],dl[N],dr[N];
long long a[N],D;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>ID>>T;
	while(T--){
		cin>>n>>D;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			pr[i]=i==1?1:pr[i-1];
			while(pr[i]<i&&a[i]-a[pr[i]]>D)pr[i]++;
		}
		for(int i=n;i;i--){
			nxt[i]=i==n?i:nxt[i+1];
			while(nxt[i]>i&&a[nxt[i]]-a[i]>D)nxt[i]--;
		}
		for(int i=1;i<=n;i++){
			if(i^nxt[i])jl[nxt[i]]++;
			if(i^pr[i])jr[pr[i]]++;
		}
		for(int i=1;i<=n;i++)dl[i]=jl[i]+(pr[i]^i&&nxt[pr[i]]==i?dl[pr[i]]:0);
		for(int i=n;i;i--)dr[i]=jr[i]+(nxt[i]^i&&pr[nxt[i]]==i?dr[nxt[i]]:0);
		long long ans=0;
		for(int i=1;i<n;i++)
			if(a[i+1]-a[i]<=D){
				int x=jl[i+1]-(nxt[i]==i+1)+(pr[i]^i&&nxt[pr[i]]==i+1?dl[pr[i]]:0),y=jr[i]-(pr[i+1]==i)+(nxt[i+1]^(i+1)&&pr[nxt[i+1]]==i?dr[nxt[i+1]]:0);
				ans+=1ll*x*y;
			}
		for(int i=1;i<=n;i++)jl[i]=jr[i]=dl[i]=dr[i]=0;
		cout<<ans<<"\n";
	}
	return 0;
}