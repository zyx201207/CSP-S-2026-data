#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,w,ww,ans=1;
ll num_z,num_f;
ll key=-1,keyy=-1;;
ll a[500050];
ll t_z[200020],t_f[200020];
bool max_l=false,max_r=false;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ll maxn=a[1];
	for(int i=2;i<=n;i++){
		if(m-abs(maxn-a[i])>=0){
			ans++;
			m-=abs(maxn-a[i]);
		}else{
			break;
		}
	}
	cout<<ans;
} 
