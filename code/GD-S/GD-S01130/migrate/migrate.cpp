#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],l[2000005],r[2000005],f[2000005],g[2000005];
vector<int>v1[2000005],v2[2000005];
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i],v1[i].clear(),v2[i].clear();
		for(int i=1,j=1;i<=n;i++){while(j<n&&x[j+1]-x[i]<=d)j++;r[i]=j,v1[r[i]].emplace_back(i);}
		for(int i=n,j=n;i>=1;i--){while(j>1&&x[i]-x[j-1]<=d)j--;l[i]=j,v2[l[i]].emplace_back(i);}
		for(int i=1;i<n;i++){f[i]=1;for(int v:v1[i])if(v>l[i]&&v<i)f[i]++;if(l[i]<i&&r[l[i]]==i)f[i]+=f[l[i]];}
		for(int i=n;i>1;i--){g[i]=1;for(int v:v2[i])if(v>i&&v<r[i])g[i]++;if(r[i]>i&&l[r[i]]==i)g[i]+=g[r[i]];}
		int ans=0;
		for(int i=2;i+1<n;i++){
			int c1=0,c2=0;
			for(int v:v1[i+1])if(v>l[i]&&v<i)c1++;if(l[i]<i&&r[l[i]]==i+1)c1+=f[l[i]];
			for(int v:v2[i])if(v>i+1&&v<r[i+1])c2++;if(i+1<r[i+1]&&l[r[i+1]]==i)c2+=g[r[i+1]];
			ans+=c1*c2;
		}
		cout<<ans<<"\n";
	}
}
