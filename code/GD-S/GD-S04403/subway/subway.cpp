#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=0x3f3f3f3f;
int w[5*114514],st[5*114514];
int li[5*100001][505];
vector <int> xb[5*114514];
ll c,n,m,d,q;
ll lin[514][514];
set<ll> hcz;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset (lin,INF,sizeof(lin));
	cin >> c >> n >> m >> d >> q;
	for(ll i=1;i<=m;i++)cin >> w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin >> k;
		for(ll j=1;j<=k;j++){
			ll x,t;
			cin >> x >> t;
			st[x]++;
			if(st[x]>1)hcz.insert(x);
			xb[x].push_back(i);
			li[x][i]=t;
		}
	}
	for(auto it=hcz.begin();it!=hcz.end();it++){
		ll i=*it;
		for(ll j=0;j<(ll)xb[i].size();j++){
			for(ll k=0;k<(ll)xb[i].size();k++){
				if(j==k)continue;
				ll lin1=xb[i][j],lin2=xb[i][k];
				lin[lin1][lin2]=min(lin[lin1][lin2],(ll)li[i][lin1]+li[i][lin2]);
			}
		}
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			for(ll k=1;k<=n;k++){
				if(i==j||i==k||j==k)continue;
				lin[i][j]=min(lin[i][k]+lin[k][j],lin[i][j]);
			}
	for(ll i=1;i<=n;i++)lin[i][i]=0;
	while(q--){
		ll x,y,ans=0,sum=INF;
		cin >> x >> y;
		ans+=w[x]+w[y];
		for(ll i=0;i<(ll)xb[x].size();i++){
			for(ll j=0;j<(ll)xb[y].size();j++){
				ll linx=xb[x][i],liny=xb[y][j];
				ll lix=li[x][linx],liy=li[y][liny];
//				cout << lix << ' ' << liy << ' ' << lin[linx][liny] <<endl;
				sum=min((ll)(lix+liy+lin[linx][liny]),sum);
			}
		}
		ans+=sum;
		cout << ans;
		puts("");
	}
	return 0;
}

