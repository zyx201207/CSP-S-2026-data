#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll m,n,a[1000086],b[1000086];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	cin>>n>>m;
	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n;i++){
		if(a[i-1]==a[i+1]){
			a[i]=a[i-1];
			a[i]++;
		}
		
	}
	for(ll i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
