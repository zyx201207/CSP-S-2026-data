#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int C,T;
int n;
int L[N],R[N];
ll x[N],d,ans;
ll pre[N],suf[N];
vector<int>h[N],s1[N],s2[N];
int c[N];
void solve(){ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)h[i].clear(),c[i]=0,s1[i].clear(),s2[i].clear();
	int j=1;
	for(int i=1;i<=n;i++){
		while(x[i]-x[j]>d)j++;
		if(i==j)L[i]=0;
		else L[i]=j;
		if(j)s1[j].emplace_back(i);
	}
	j=n;
	for(int i=n;i>=1;i--){
		while(x[j]-x[i]>d)j--;
		if(i==j)R[i]=0;
		else R[i]=j;
		if(j)s2[j].emplace_back(i);
	}
	for(int i=1;i<=n;i++){
		pre[i]=1;j=L[i];
		if(j&&R[j]==i)pre[i]+=pre[j];
		for(int o:s2[i])if(o!=j)pre[i]++;
	}
	for(int i=n;i>=1;i--){
		suf[i]=1;j=R[i];
		if(j&&L[j]==i)suf[i]+=suf[j];
		for(int o:s1[i])if(o!=j)suf[i]++;
	}
	for(int l=1;l<=n;l++){
		int i=R[l],r=R[i];
		if(!r)continue;
		j=L[r];
		if(L[j]!=l||j!=i-1)continue;
		ans+=(pre[l]-1)*(suf[r]-1);
	}
	for(int l=1;l<=n;l++){
		int i=R[l],r=R[i];
		if(!r)continue;
		j=L[r];
		if(!j||j!=i-1)continue;
		ans+=suf[r]-1;
	}

	for(int r=1;r<=n;r++){
		int j=L[r],l=L[j];
		if(!l)continue;
		int i=R[l];
		if(!j||j!=i-1)continue;
		ans+=pre[l]-1;
	}
	for(int l=1;l<=n;l++){
		if(R[l]){
			h[R[l]].emplace_back(l);
		}
	}
	for(int i=n;i>=1;i--){
		for(int j:h[i]){
			if(i-1>j)ans+=c[i-1];
		}
		if(L[i])c[L[i]]++;
	}
	cout<<ans<<"\n";
}
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)solve();
	return 0;
}
