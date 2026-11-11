//GZ-S00251 ¿Ó∫Ë’‹
#include<bits/stdc++.h>
#define endl '\n'
#define ls i<<1
#define rs (i<<1|1)
#define fi first
#define se second
#define pb push_back
using namespace std;
template<typename U,typename V>bool cmin(U &x,V y){return y<x?x=y,true:false;};
template<typename U,typename V>bool cmax(U &x,V y){return y>x?x=y,true:false;};
#define to(i,o,p) for(ll i=(o);i<=(p);i++)
#define un(i,o,p) for(ll i=(o);i>=(p);i--)
mt19937 rng(time(0));
using ll=long long;
using pll=pair<ll,ll>;
const int int_inf=1E9+7;
const ll inf=1E18+7;
const int mod=1E9+7;
const int P=0;
const int M=1E12;
const int N=5E5+10;
ll n,m,a[N],ans,Max,sum,num,l=1,r;
void solve(){
	cin>>n>>m;
	to(i,1,n){cin>>a[i];}
	sort(a+1,a+n+1);
	to(i,1,n){
		++r;num++;sum+=a[i];
		while(num*a[r]-sum>m){
			num--;
			sum-=a[l++];
		}
		cmax(Max,num);
	}
	cout<<Max<<endl;
}
int main(){//A
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}
