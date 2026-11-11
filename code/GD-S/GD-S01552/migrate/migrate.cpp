#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int c,T;
ll n,d,a[N],f[N][N],cnt[N][N],b[N];
map<ll,ll>mp;
void dfs(int x,int y,int step){
	if(step>f[mp[x]][mp[y]])return;
	if(!b[mp[y]])return; 
	if(y>a[n])return;
	if(step<f[mp[x]][mp[y]])f[mp[x]][mp[y]]=step,cnt[mp[x]][mp[y]]=0;
	if(step==f[mp[x]][mp[y]])cnt[mp[x]][mp[y]]++;
	for(int i=1;i<=d;i++)dfs(x,y+i,step+d);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		memset(f,0x3f,sizeof(f));
		memset(cnt,0,sizeof(cnt));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mp[a[i]]=i;
			b[mp[a[i]]]++;
		}
		for(int i=1;i<=n;i++)dfs(a[i],a[i],0);
		ll ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(cnt[mp[a[i]]][mp[a[j]]]==2)ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
} 
