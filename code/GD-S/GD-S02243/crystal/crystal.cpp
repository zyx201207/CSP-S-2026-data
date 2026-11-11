#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5;
ll n,m;
ll a[N+1]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>5000){
		ll sel=a[2]-a[1];
		for(ll i=1;i<=n;i++){
			if(i*(i-1)*sel/2>m){
				cout<<i-1;
				return 0;
			}
		}	
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			ll sum=0;
			for(int j=i+1;j<=n;j++){
				sum+=(j-i)*(a[j]-a[j-1]);
				if(sum<=m){
					ans=max(j-i+1,ans); 
				}
				else break;
			}
		}
		cout<<ans;
	}
	return 0;
} 
