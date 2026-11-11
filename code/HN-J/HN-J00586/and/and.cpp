#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m;
ll arr[N];
bool cmp(ll a,ll b){
	return a>b;
}
ll a=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(arr+1,arr+1+n,cmp);
	for(int j=1;j<=n-m;j++){
		ll ans=arr[j];
		for(int i=2;i<=m;i++){
			ans&=arr[i];
		}
		a=max(a,ans);
	}	
	cout<<a;
	return 0;
} 
