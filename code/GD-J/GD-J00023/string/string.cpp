#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],ra[200005];
char c[200005],rc[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	ll len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		ra[n-i+1]=a[i],rc[n-i+1]=c[i];
	}ll i=0,j=0,x=1,y=1,ans=0;
	while(i<=len&&j<=len&&x<=n&&y<=n){
		ll lx=x,ly=y;
		int ax=0;
		while(i<=j){
			ax=0;
			if(c[x]!=rc[y]){
				ans+=min(j-i,i+a[x]);
				ax+=min(j-i,i+a[x]);
			}
			i+=a[x];
			x++;
		}while(i>j){
			ax=0;
			if(c[lx]!=rc[y])ans+=min(i-j,j+ra[y]),ax+=min(i-j,j+ra[y]);
			j+=ra[y];
			y++;
		}
	}cout<<ans/2;
	return 0;
}
