#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,ar[N],mx=-1,s=-1,ma=-1,x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>ar[i];
		mx=max(mx,ar[i]);
		if(s==-1)s=ar[i];
		else s&=ar[i];
	}
	if(m==1)cout<<mx;
	else if(m==n)cout<<s;
	else if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				x=ar[i]&ar[j];
				ma=max(x,ma);
			}
		}cout<<ma;
	}
	return 0;
}
