#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
ll n,m,a[500010],ans=1,l,r,len,nd;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	a[0]=a[1];
	l=1,r=1,len=1,nd=0;
	for(;r<=n;r++){
		nd+=(a[r]-a[r-1])*len;
		len++;
		while(nd>m&&l<r){
			nd-=(a[r]-a[l]);
			l++;
			len--;
		}
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}
