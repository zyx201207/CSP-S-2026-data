#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LL long long
#define put(x) cerr<<x<<'\n'
ll read(){ll x=0,w=1;char c=getchar();while('0'>c||'9'<c){if(c=='-')w=-1;c=getchar();}while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}return x*w;}
const ll N=5010,NN=2e6+10;
ll nxt[N],lst[N],sm[N];
ll a[N];
ll dis[N];
ll n,as=0;
LL d;
void work(){
	as=0;
	n=read();d=read();
	for(ll i=1;i<=n;i++)a[i]=read();
	for(ll i=n,qr=n;i;i--){
		while(a[qr]-a[i]>d&&qr>i)qr--;
		nxt[i]=qr;
	}
//	for(ll i=1;i<=n;i++){
//		nxt[i]=i;while(nxt[i]<=n&&a[nxt[i]]-a[i]<=d)nxt[i]++;nxt[i]--;
//	} 
//	for(ll i=1;i<=n;i++)cerr<<a[i]<<' ';put("");
//	for(ll i=1;i<=n;i++)cerr<<"nxt "<<nxt[i]<<'\n';
	for(ll i=1;i<n;i++){
//		cerr<<"i "<<i<<'\n';
		for(ll j=i;j<=n;j++)sm[j]=dis[j]=lst[j]=0;
		for(ll j=i;j<=n;j++){
//			cerr<<"j "<<j<<'\n';
			if(dis[nxt[j]])continue;
			for(ll k=nxt[j];k>j;k--){
				if(dis[k]){
					lst[nxt[j]]=k+1;if(dis[k]==dis[j]+1)lst[nxt[j]]=lst[k];break;
					
				}
				dis[k]=dis[j]+1;
//				cerr<<"disk "<<k<<' '<<dis[k]<<'\n';
			}
			if(!lst[nxt[j]])lst[nxt[j]]=j+1;
			for(ll k=nxt[j];k>=lst[nxt[j]];k--)lst[k]=lst[nxt[j]];
		}
		lst[i]=i;
//		cerr<<"lst ";
//		for(ll j=i;j<=n;j++)cerr<<lst[j]<<' ';put("");
		ll nsm=0;sm[i]=1;sm[i+1]=-1;
//		cerr<<"sm ";
		
		for(ll j=i;j<=n;j++){
			nsm+=sm[j];
//			cerr<<sm[j]<<' ';
			if(nsm==2)as++;
			if(dis[nxt[j]]==dis[j]+1)sm[lst[nxt[j]]]+=nsm,sm[nxt[j]+1]-=nsm;
		}
//		put("");
	}
	cout<<(long long)as<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c=read(),t=read();while(t--)work();
//	auto ed=clock();cerr<<ed<<"ms\n";
}
/*
0 1
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956


*/
