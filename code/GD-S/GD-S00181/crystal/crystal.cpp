#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define put(x) cerr<<x<<'\n'
ll read(){ll x=0,w=1;char c=getchar();
while('0'>c||'9'<c){if(c=='-')w=-1;c=getchar();}
while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
return x*w;}
const ll N=5e5+10;
ll a[N];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	auto st=clock();
	n=read(),m=read();
	for(ll i=1;i<=n;i++)a[i]=read();
//	auto ed=clock();
//	cerr<<ed<<' '<<"ms\n";
//	cin>>n>>m;
//	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll nm=0,sm=0;
	ll as=0;
	for(ll i=1,ql=1;i<=n;i++){
		sm+=nm*(a[i]-a[i-1]);
		while(a[i]==a[i+1])i++;
		while(ql<=i&&sm>m){
			sm-=a[i]-a[ql];nm--;ql++;
		}
		as=max(as,i-ql+1);
		nm=i-ql+1;
	}
	cout<<as;
}
/*
5 8
-3 -1 2 2 7
*/
