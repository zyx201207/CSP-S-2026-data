#include<bits/stdc++.h>
#define ll long long
#define db double
#define bint __int128
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define gc getchar
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
int ret(); bool vst;
const int N=1e6+5,mod=998244353;
int n,T,Tid;
ll x[N],d;
void read(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
}
//  <dis,cnt>
pair<int,pii> q[N]; int hh,tt;
bool tag[N];
int calc(int p){
	ll res=0;
	hh=0,tt=-1; q[++tt]=mkp(p,mkp(0,1));
	for(int i=p+1;i<=n;i++){
		while(hh<=tt && x[i]-x[q[hh].fi]>d)hh++;
		int mn=q[hh].se.fi+1,ct=0;
		for(int j=hh;j<=tt;j++){
			if(q[j].se.fi+1!=mn)break;
			ct+=q[j].se.se; chkmin(ct,3);
			if(ct==3)break;
		}
		tag[i]=(ct==2),res+=tag[i];
		while(hh<=tt && q[tt].se.fi>mn)tt--;
		q[++tt]=mkp(i,mkp(mn,ct));
	}
	return res;
}
void sol1(){
	read();
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=calc(i);
	cout<<ans<<endl;
}
void sol2(){
	read(),calc(1);
	ll ans=0;
	for(int i=2;i<=n;i++)
		if(tag[i])ans+=n-i+1;
	cout<<ans<<endl;
}
bool ved; int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>Tid>>T;
	while(T--){
		if(Tid==11||Tid==12)sol2();
		else sol1();
	}
	return ret();
}
int ret(){cerr<<"Space used: "<<abs((&vst)-(&ved))/1024.0/1024.0<<" MB."<<endl; return 0;}
//  Oct31==Dec25?
