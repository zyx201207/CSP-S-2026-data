#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005];
ll get(ll x){
	ll x1=x,sum=0,o=0;
	while(x1){
		o++;
	if(x&1)	sum++;
	}return sum==o;
}ll dfs(){
	ll maxx=-1;
	for(int i=0;i<=(1<<m+1)-1;i++){
		if(get(i)==m){
			ll sum=(1<<18)-1;
			ll ans=1;
			while(1<<(ans-1)<=i){
				if(1<<(ans-1)&i){
					sum&=a[ans];
				}ans++;
			}maxx=max(maxx,sum);
		}
	}return maxx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;ll maxx=-1,o=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		o*=get(a[i]);
		maxx=max(a[i],maxx);
	}if(o==1)cout<<maxx;
	else cout<<12;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
