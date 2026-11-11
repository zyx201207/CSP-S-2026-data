#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

ll t[40]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,
	16384,32768,65536,131072,262144,524288,1048576,2097152,
	4194304,8388608,16777216,33554432,67108864,134217728,
	268435456,536870912,1073741824};
struct node{
	string two;
	ll id;
}an;
ll a[200010];

string chai(ll x){
	string ans;
	for(ll i=30;i>=0;i--){
		if(x>=t[i]) ans+='1',x-=t[i];
		else ans+='0';
	}return ans;
}
vector<node> v,v2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,maxn=0;
	cin>>n>>m;
	
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		an.two=chai(a[i]);
		an.id=a[i];
		v.push_back(an);
	}
	
	for(ll i=0;i<=31;i++){
		for(ll j=0;j<ll(v.size());j++){
			if(v[j].two[i]=='1'){
				v2.push_back(v[j]);
			}
		}if(ll(v2.size())==m){
			ll ans=v2[0].id;
			for(ll j=1;j<ll(v2.size());j++) ans=ans&v2[j].id;
			cout<<ans;
			return 0;
		}else if(ll(v2.size())>m){
			ll ans=v2[0].id;
			for(ll j=1;j<ll(v2.size());j++) ans=ans&v2[j].id;
			maxn=max(maxn,ans);
			v=v2;
			v2.clear();
		}else v2.clear();
	}cout<<maxn;
}
