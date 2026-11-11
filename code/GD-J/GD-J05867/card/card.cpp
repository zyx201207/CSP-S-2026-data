#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005];
ll v[500005],x[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]]++;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		if(a[1]==a[2]) cout<<2;
		else cout<<1<<' '<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			if(v[a[j]]==1) x[a[j]]++;
			else {
				x[a[j]]++;
				break;
			}
		}
		v[a[i]]--;
	}
	for(int i=1;i<=m;i++){
		cout<<x[i]<<' ';
	}
	
	
	return 0;
} 
