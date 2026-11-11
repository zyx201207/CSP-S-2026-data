#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,leg;
struct node{
	ll a;char c;
}arr[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].a>>arr[i].c;
		leg+=arr[i].a;
	}
	ll l=1,r=n,ans=0;
	for(ll i=1;i<=leg/2;){
		ll adleg=min(arr[l].a,arr[r].a);
		if(arr[l].c!=arr[r].c){
			ans+=adleg;
		}
		arr[l].a-=adleg;
		arr[r].a-=adleg;
		if(arr[l].a==0) l++;
		if(arr[r].a==0) r--;
		i+=adleg;
	}
	cout<<ans;
	return 0;
}
/*
第 
二 
题 
就 
是 
离 
散 
化 
？
！ 
*/
