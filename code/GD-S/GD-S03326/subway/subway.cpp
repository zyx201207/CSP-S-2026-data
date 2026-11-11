#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define ll long long
#define gc getchar 
#define mn 505
#define mm 500005
#define pb push_back
#define pii pair<int,int>
#define pil pair<int,ll>
#define vp vector<pil>
#define mp make_pair
#define sz size
#define fr first
#define se second
#define inf 0x3f3f3f3f3f3f3f3f
#define F(_,x,y) for(int _=x;_<=y;_++)
using namespace std;
int c,n,m,d,q,k,a,t,x,y;vp v[mm];
ll w[mm],ds[mn][mn],as;
ll rd(){ll x=0;char c=gc();int f=(c=='-');while(c<48)c=gc();
	while(c>47)x=x*10+c-48,c=gc();return x*(f?(-1):1);
}void cmn(ll&x,ll y){x=(x<y?x:y);}
int main(){freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();F(_,1,m)w[_]=rd();
	F(_,1,n){k=rd();while(k--){a=rd(),t=rd(),v[a].pb(mp(_,t));}}
	F(i,1,n)F(j,1,n)ds[i][j]=inf;F(_,1,n)ds[_][_]=0;
	F(_,1,m)for(auto x:v[_])for(auto y:v[_])cmn(ds[x.fr][y.fr],x.se+y.se);
	F(_,1,n)F(x,1,n)F(y,1,n)cmn(ds[x][y],ds[x][_]+ds[_][y]);
	while(q--){x=rd(),y=rd(),as=inf;for(auto i:v[x])for(auto j:v[y])cmn(as,ds[i.fr][j.fr]+i.se+j.se);printf("%lld\n",as+w[x]+w[y]);}return 0;
}
