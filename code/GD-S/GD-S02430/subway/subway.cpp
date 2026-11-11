#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm=5e5+5,mn=505,in=4e18;
ll c,n,m,d,q,w[mm],ki,di[mn][mn],dt,x,y,ans;
struct o{
	ll id,t;
}sr;
vector<o>v[mm];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}for(ll i=1;i<=n;i++){
		cin>>ki;
		for(ll j=0;j<ki;j++){
			cin>>dt>>sr.t;
			sr.id=i;
			v[dt].push_back(sr);
		}
	}for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i!=j)di[i][j]=in;
		}
	}
	for(ll i=1;i<=m;i++){
		ll vs=v[i].size();
		/*for(ll j=0;j<vs;j++){
			for(ll k=0;k<vs;k++){
				di[v[i][j]][v[i][k]]=min(di[v[i][j]][v[i][k]],)
			}
		}*/
		for(o j:v[i]){
			for(o k:v[i]){
				di[j.id][k.id]=min(di[j.id][k.id],j.t+k.t);
				di[k.id][j.id]=di[j.id][k.id];
			}
		}
	}for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				di[i][j]=min(di[i][j],di[i][k]+di[k][j]);
			}
		}
	}while(q--){
		cin>>x>>y;
		ans=in;
		ll ba=w[x]+w[y];
		for(o i:v[x]){
			for(o j:v[y]){
				ans=min(ans,ba+i.t+j.t+di[i.id][j.id]);
			}
		}cout<<ans<<'\n';
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
