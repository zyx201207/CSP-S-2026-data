#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],b[200005];
ll n1(int x){
	ll t=x,ans=0;
	while(t>0){
		ans+=t%2;
		t/=2;
	}
	return ans;
}
bool cmp(int x,int y){
	return n1(x)>n1(y);
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	ll an=a[0];
	while(m--){
		ll maxn=-1,w;
		for(ll j=0;j<n;j++){
			if(maxn<(an&a[j])&&!b[j]){
				maxn=(an&a[j]);
				w=j;
			}
		}an=maxn;
		b[w]=1;
	}cout<<an;
	return 0;
}
