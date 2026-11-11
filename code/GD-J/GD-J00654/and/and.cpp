#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,key=-1,keyy=-1,keyyy=1,w;
ll a[200020],t[1100000];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(t,0,sizeof(t));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		key=max(key,a[i]);
		t[a[i]]++;
	}
	if(m==1){
		cout<<key;
		return 0;	
	}
	if(m==n){
		ll ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(t[a[i]]>=keyy&&t[a[i]]>1){
			keyy=t[a[i]];
			w=a[i];
		}
	}
	cout<<max(a[m],w);
}
