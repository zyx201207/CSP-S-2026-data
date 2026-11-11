#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e5;
ll n,m,x,l,sumend=-1,sum[2][MAXN];
vector<ll> v;
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>x;
		if((!sum[0][abs(x)]&&x<0)||(!sum[1][abs(x)]&&x>0)) v.push_back(x);
		x<0?sum[0][abs(x)]++:sum[1][abs(x)]++;
	}
	for(ll i=0;i<v.size();i++){
		x=0,l=0;
		for(ll j=i+1;j<=v.size();j++){
			if(v[j-1]<0){
				l=l+sum[0][abs(v[j-1])];
				x=x+l*(v[j]-v[j-1]);
				if(x>m) break;
			}
			else{
				l=l+sum[1][abs(v[j-1])];
				x=x+l*(v[j]-v[j-1]);
				if(x>m) break;
			}
		}
		sumend=max(sumend,l);
	}
	cout<<sumend<<"\n";
	return 0;
}
