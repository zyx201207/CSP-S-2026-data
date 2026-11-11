#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],b[2][300010],w,da[300010],zs[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=n;i>=1;i--)
		cin>>a[i];
	for(ll i=1;i<=n;i++){
		w++;
		b[0][w]=i;
		b[1][w]=a[i];
		zs[a[i]]++;
		if(zs[a[i]]==2){
			zs[a[i]]=1;
			w--;
			while(b[1][w]!=a[i]){
				da[b[1][w]]+=i-b[0][w];
				zs[b[1][w]]--;
				w--;
			}
		}
	}
	while(w!=0){
		cout<<b[1][w]<<" ";
		da[b[1][w]]+=n-b[0][w]+1;
		w--;
	}
	cout<<endl;
	for(ll i=1;i<=m;i++){
		cout<<da[i]<<" ";
	}
}
