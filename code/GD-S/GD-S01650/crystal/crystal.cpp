#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,val[N],ans,m,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>val[i];
	}sort(val+1,val+1+n);
	for(ll i=1,l=1;i<=n;i++){
		sum+=(i-l)*(val[i]-val[i-1]);
		while(l<=i and sum>m){
			sum-=val[i]-val[l++];
		}ans=max(ans,i-l+1);
	}cout<<ans;
	return 0;
} 
