#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a[50005],f[50005][50005],ans=0;
struct mm{
	ll c,z;
};
void cc(ll x){
	ll ch[50005];
	for(ll i = 1; i < x ; i ++){
		ch[i]=a[x]-a[i];
	}
	sort(ch+1,ch+x);
	for(ll i = 1 ; i < x ; i ++){	
		f[x][i]=f[x][i-1];
		f[x][i]+=ch[i];
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(ll i = 1 ; i <= n ; i ++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i = 2 ; i <= n ; i ++){
		cc(i);
	}
	
	for(ll i = 1 ; i <= n ; i ++){
		for(ll j = 1 ; j < i ; j ++){
			if(f[i][j]<=m&&j>ans){
				ans=j;
			}

		}
	}
	cout<<ans+1;
}

