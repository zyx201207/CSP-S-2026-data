#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e6+10;
int n;
int pre[N],suf[N],L[N],R[N]; 
ll ans,k,a[N];
int s[N];
vector<pair<int,int>> v1[N]; 
void solve(){
	ans=0;cin>>n>>k;
	for(int i=0;i<=n+1;i++)L[i]=R[i]=pre[i]=suf[i]=0,v1[i].clear(),s[i]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,j=1;i<=n;i++){
		while(j+1<=n&&a[j+1]-a[i]<=k)j++;
		R[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(j-1>=1&&a[i]-a[j-1]<=k)j--;
		L[i]=j;
	}
	for(int i=1;i<=n;i++){
		if(R[i]>i){
			pre[R[i]]++;
			if(L[R[i]]==i)pre[R[i]]+=pre[i];
		}
	}
	for(int i=n;i>=1;i--){
		if(L[i]<i){
			suf[L[i]]++; 
			if(R[L[i]]==i)suf[L[i]]+=suf[i];
		}
	} 
	for(int i=1;i<=n;i++){
		if(i<R[i]&&R[i]<R[R[i]]&&L[L[R[R[i]]]]==i&&R[i]==L[R[R[i]]]+1)ans+=1ll*pre[i]*suf[R[R[i]]];
	}
	for(int i=1;i<=n;i++){
		if(i<R[i]&&R[i]<R[R[i]]&&L[L[R[R[i]]]]<=i&&R[i]==L[R[R[i]]]+1)ans+=suf[R[R[i]]];
	}
	for(int i=1;i<=n;i++){
		if(L[i]<i&&L[L[i]]<L[i]&&R[R[L[L[i]]]]>=i&&L[i]+1==R[L[L[i]]])ans+=pre[L[L[i]]];
	}
	for(int i=1;i<=n;i++)v1[R[R[i]]].push_back({R[i],1}),v1[R[i]].push_back({R[i],-1});
	for(int i=1;i<=n;i++){
		s[L[i]+1]++;
		for(auto j:v1[i])ans+=j.second*s[j.first];
	}
//	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(R[i]<j&&R[R[i]]>=j&&L[j]+1==R[i])ans++;
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int cid,T;cin>>cid>>T;
	while(T--)solve();
}

