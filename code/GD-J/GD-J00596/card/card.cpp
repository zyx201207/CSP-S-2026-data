#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll t[300005];//Õ∞ 
ll st[500005],idx;// ÷∂Ø’ª£¨’ª±Í£®top£© 
ll n,m;
ll a[500005];

ll find(ll x){
	for(ll i=0;i<idx;i++){
		if(st[i]==x) return i;
	}
	return -1;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		idx=0; st[0]=0;
		for(ll j=i;j<=n;j++){
			ll x=find(a[j]);
			if(x==-1){
				st[idx++]=a[j];
			}
			else{
				idx=x;
				st[idx++]=a[j];
			}
		}
		for(ll i=0;i<idx;i++){
			t[st[i]]++;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	cout<<endl;
	return 0;
}
