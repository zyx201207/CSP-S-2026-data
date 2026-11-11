#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
ll c,t,n,m,d,cnt;
ll net[maxn],pre[maxn];
ll x[maxn],ans;
ll book[maxn];
bool check(ll a,ll b,ll c,ll d){
	if(d-a<=m) return false;
	if(c-a>m or d-b>m) return false;
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		ans=cnt=0;
		//cout<<n<<"   dfdfadf "<<m<<endl; 
		for(ll i=1;i<=n;i++) cin>>x[i];
		for(ll i=4;i<=n;i++) book[i]=check(x[i-3],x[i-2],x[i-1],x[i]);
		for(ll i=4;i<=n;i++){
			if(book[i]==1) net[++cnt]=i;
			//cout<<i<<" "<<book[i]<<endl;
		}
		for(ll i=1;i<=n;i++) book[i]=0;
		for(int i=1;i<=cnt;i++){
			book[net[i]]=book[net[i]-1]=book[net[i]-2]=book[net[i]-3]=i;
		}
		for(ll i=0;i<=n+1;i++) pre[i]=0;
		/*for(int i=1,j=1;i<=n;i++){
			if(i!=1 and j<n) while(j<n and x[j+1]<=x[i]+m) j++;
			if(j==n and x[n]<x[i]+m) j++;
			if(j<=n) pre[j]=i;
			net[i]=j;
		}*/
		int u=0;
		for(ll i=1;i<=n;i++){
			if(book[i]==0) pre[u]++;
			else u=book[i];
			//cout<<i<<" "<<pre[i]<<endl;
		}
		for(ll i=1;i<=cnt;i++){
			ans+=1;
			ans+=pre[i-1];
			ans+=pre[i+1];
			ans+=pre[i-1]*pre[i+1];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
