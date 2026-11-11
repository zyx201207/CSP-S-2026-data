#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=2e5+10;
ll n,m,a[maxn],ans=0,b=0;
bool cmp(ll aa,ll bb){
	return aa>bb;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(ll i=a[1];i>0;i/=2){
		b++;
	}
	for(ll i=1;i<=m;i++){
		if(a[i]&(1<<b))ans=ans&a[i];
		else{
			for(ll j=1;j<i;j++)a[j]=a[j]-(1<<b);
			sort(a+1,a+n+1,cmp);
			i=1;
			b--;
			if(b<=0){
				cout<<0<<'\n';
				return 0;
			}
			ans=a[1];
			//cout<<a[1]<<" "<<b<<'\n';
		}
	}
	cout<<ans;
	return 0;
}
