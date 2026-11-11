#include <iostream>
#include <cstdio>
#define ll long long
#define H <<' '<<
using namespace std;
ll n,m,a[500005],p[300005],ans[300005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("card.in","r",stdin);
//	freopen("card/card4.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(p[a[j]]==0){
				p[a[j]]=j;
				continue;
			}
			for(ll k=1;k<=m;k++){
				if(p[k]>p[a[j]]){
					p[k]=0;
				}
			}
			p[a[j]]=j;
		}
		for(ll j=1;j<=m;j++){
			if(p[j]!=0){
				ans[j]++;
				p[j]=0;
			}
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
// 24
