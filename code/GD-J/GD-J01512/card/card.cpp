#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
ll n,m,arr[N],b[N*2],ans[N];
vector<pair<ll,ll> >g[N];
ll d[N];
pair<pair<ll,ll>,pair<char,char> >dijsktra(ll st){
	//freopen(traVel.int,"R",using namespace std)£» 
	memset(d,0x3f,sizeof d);
	priority_queue<pair<ll,ll> >pq;
	d[st]=0;
	pq.push(make_pair(0,st)); 
	while(!pq.empty()){
		ll u=pq.top().second;
		for(auto x:g[u]){
			ll v=x.first,w=x.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				pq.push(make_pair(-w,v));
			} 
		}
	}
	ll a=d[1],k=d[n],r=998244353,p=1e9+7;
	if(a==k)return make_pair(make_pair(a,k),make_pair('1','='));
	else return make_pair(make_pair(r,p),make_pair('+','+'));
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&arr[i]);
	ll idx=0;
	map<ll,ll>mp;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp[arr[j]]>1){
				mp[arr[j]]++;
				while(b[idx]!=arr[j]&&idx>=1){
					mp[arr[idx]]--;
					//cout<<"-"<<arr[idx]<<" ";
					idx--;
				}
				mp[arr[j]]--;
				idx--;
			}
			b[++idx]=arr[j];
			mp[arr[j]]++;
			//cout<<"+"<<arr[j]<<" ";
		}
		for(int j=1;j<=m;j++)ans[j]+=(mp[j]>0?1:0);
		for(int j=1;j<=idx;j++)cout<<b[j]<<" ";
		cout<<endl;
	}
	for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
	return 0;
}
//freopen("cand.ans","W",stdin);
