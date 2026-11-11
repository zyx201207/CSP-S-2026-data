#include<bits/stdc++.h>
#define ll long long
const ll N=5*1e5+100;
using namespace std;
ll n,m;
ll a[N],c[N];
bool A=1,B=1;
ll cc(ll l,ll r){
	ll x=0,p=1;
	for(int i=l+1; i<=r; i++){
		x=(a[i]-a[i-1])*p+x;
		//cout<<x<<" ";
		p++;
	}
	//cout<<endl;
	return x;
}
struct zhe_dao_ti_hao_nan{
	ll x;
	ll gs; 
};
bool cmp(zhe_dao_ti_hao_nan x,zhe_dao_ti_hao_nan y){
	return x.gs>y.gs;
}
//vector<zhe_dao_ti_hao_nan> ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	ll iloveccf=m;
	ll cha;
	ll sum=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]!=i){
			A=0;
		}
		if(i==1 or i==2){
			cha=a[2]-a[1];
		}else if(a[i]-a[i-1]!=cha){
			B=0;
		}
	}
	//cout<<A<<" "<<B;
	sort(a+1,a+n+1);
	if(B==1 or A==1){
		//cout<<cha<<endl;
		if((a[1]+a[n])*n/2==m){
			cout<<n;
			return 0;
		}
		ll ewe=cha,i;
		for(i=1; i<=n; i++){
			if(m<ewe){
				break;
			}else{
				m-=ewe;
			}
			ewe+=cha;
		}
		cout<<i;
		return 0;
	}
	bool ccfnb=1;
	for(int i=1; i<n; i++){
		iloveccf-=(a[n]-a[i]);
		if(iloveccf<0){
			ccfnb=0;
		}
	}
	if(ccfnb){
		cout<<n;
		return 0;
	}
	//cout<<"我在这里"<<cc(2,5)<<endl; 
//	for(int i=2; i<=n; i++){
//		c[i]=(a[i]-a[i-1])*(i-1)+c[i-1];
//	}
	ll ans=-1e13;
	for(int i=1; i<n; i++){
		for(int j=i+1; j<=n; j++){
			ll x=cc(i,j);
			ll gs=j-i+1;
			if(x<=m){
				ans=max(gs,ans);
			}
		}
	}
	cout<<ans;
//	ll i;
//	for(i=1; i<=n; i++){
//		if(c[i]>m){
//			break;
//		}
//	}
//	cout<<i-1;
	return 0;
}
/*这道题的A与B特殊性质难道不是同一个东西吗(我写了102行的屎山)*/
