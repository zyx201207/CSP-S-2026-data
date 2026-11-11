#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[10010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ljh=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==a[j]){
				ljh==a[i]+a[j];
			}


			}
		}
		cout<<ljh;


	return 0;
}
