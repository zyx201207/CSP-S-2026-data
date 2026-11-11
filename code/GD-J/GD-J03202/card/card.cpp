#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n;
ll a[500005];
ll a1[500005];
ll b[300005];
ll i,j,k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		fill(a1+i,a1+n+1,0);
		ll x=i;
		for(j=i;j<=n;j++){
			a1[++x]=a[j];
			for(k=i;k<x;k++){
				if(a1[k]==a1[x]){
					fill(a1+k+1,a1+x,0);
					x=k;
					break;
				}
			}
		}
		for(j=i;j<=x;j++){
			b[a1[j]]++;
		}
	}
	for(i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}	
	return 0;
}

