#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],b[300005],c[300005],di[300005];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m,d=0;
	cin>>n>>m;
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=0;i<n;i++){
		for(ll j=i;j<n;j++){
			if(b[a[j]]!=0){
				while(di[d]!=a[j]){
					b[di[d]]=0;
					d--;
				}
			}else{
				d++;
				di[d]=a[j];
				b[di[d]]=1;
			}
		}while(d){
			c[di[d]]++;
			d--;
		}
	}for(ll i=0;i<m;i++)cout<<c[i]<<" ";
	return 0;
}
