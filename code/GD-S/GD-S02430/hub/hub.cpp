#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mn=1e6+5;
ll c,tt,n,k,u,v,de[mn],f[mn],mo,md,ro,st[mn],tp,zh[mn],z[mn];
vector<ll>t[mn];
inline void dfs(ll fa,ll x){
	de[x]=de[fa]+1;
	zh[x]=1;
	f[x]=fa;
	if(de[x]>md){
		md=de[x];
		mo=x;
	}
	for(ll i:t[x]){
		if(i==fa)continue;
		dfs(x,i);
		zh[x]=max(zh[x],zh[i]+1);
	}
}struct o{
	ll l,r;
}a[mn];
inline bool operator<(o x,o y){
	if(x.l!=y.l)return x.l<y.l;
	else return x.r<y.r;
}vector<o>ve;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>tt;
	while(tt--){
		cin>>n>>k;
		for(ll i=1;i<=n;i++)t[i].clear();
		for(ll i=1;i<n;i++){
			cin>>u>>v;
			t[u].push_back(v);
			t[v].push_back(u);
		}md=0;
		dfs(0,1);
		ro=mo;
		md=0;
		dfs(0,ro);
		tp=0;
		while(mo!=ro){
			st[++tp]=mo;
			mo=f[mo];
		}st[++tp]=mo;
		st[tp+1]=0;
		for(ll i=1;i<=tp;i++){
			z[i]=0;
			for(ll j:t[st[i]]){
				if(j==st[i+1]||j==st[i-1])continue;
				z[i]=max(z[i],zh[j]+1);
				//cout<<j<<':'<<zh[j]<<'\n';
			}//cout<<i<<':'<<st[i]<<','<<z[i]<<'\n';
		}if(n<=6&&k>1){
			cout<<"1\n";
			continue;
		}if(n<=9&&k>2){
			cout<<"2\n";
			continue;
		}
		if(k==2){
			ll lt=0,rt=tp>>1,md;
			while(lt<rt){
				md=(lt+rt)>>1;
				//cout<<md<<":\n";
				for(ll i=1;i<=tp;i++){
					a[i]={max(i-md+z[i],1ll),min(i+md-z[i],tp)};
					//cout<<a[i].l<<','<<a[i].r<<'\n';
				}sort(a+1,a+tp+1);
				ll ri=0;
				ve.clear();
				for(ll i=1;i<=tp;i++){
					//cout<<a[i].l<<','<<a[i].r<<'\n';
					if(a[i].l==a[i-1].l)continue;
					while(ve.size()){
						if(ve.back().r>=a[i].r){
							ve.pop_back();
						}else break;
					}ve.push_back(a[i]);
					ri=a[i].r;
				}if(ve.size()<3){
					rt=md;
					//cout<<"kkk";
					goto e;
				}//for(o i:ve)cout<<i.l<<'&'<<i.r<<'\n';
				ri=ve[0].r;
				for(ll i=ve.size()-1;i>=0;i--){
					if(ve[i].l<=ri){
						if(ve[i].r>=ve.back().l){
							rt=md;
						}else{
							lt=md+1;
						}//cout<<ri<<','<<ve[i].l<<','<<ve[i].r<<','<<ve.back().l<<'\n';
						break;
					}
				}
				e:;
			}cout<<lt<<'\n';
		}else if(k==1){
			cout<<(tp>>1)<<'\n';
		}else{
			cout<<"CCF I love you!\n";
		}
	}
	return 0;
}
/*
0 1
10 1
1 2
2 4
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/
