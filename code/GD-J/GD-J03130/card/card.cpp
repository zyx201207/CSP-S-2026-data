#include<bits/stdc++.h>
using namespace std;
#define fname "card"
using ll=long long;
ll n,m,a[500005],b[500005],c[500005],ans[300005];
queue<ll>q;
int main(){
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	cin>>n>>m;
	ll f=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(a[i-1]>a[i])f=0;
	}
	if(f==1){
		for(ll i=1;i<=m;i++){
			cout<<b[i]<<" ";	
		}
		return 0;
	}
	for(ll i=1;i<=m;i++){
		b[i]=0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			q.push(a[i]);
			b[a[i]]++;
			if(b[a[i]]>1){
				while(j-c[a[i]]){
					q.pop();
				}
			}
			c[a[i]]=i;
		}
		for(ll i=1;i<=m;i++){
			ans[q.front()]++;
			q.pop();
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
	
} 
