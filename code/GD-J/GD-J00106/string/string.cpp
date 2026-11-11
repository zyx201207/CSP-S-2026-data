#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<ll,string>> a(n);
	ll sum=0;
	for(ll i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
		sum+=a[i].first;
	}
//	sum/=2;
//	vector<pair<int,int>> b;
//	int u=0,q111=-1;
//	while(sum>0){
//		sum-=a[u].first;
//		u++;
//		if(sum<0) q111=i;
//	}
//	if(i!=0)
	ll u=0,ans=0;
	ll l=0,r=n-1;
	while(u<sum/2){
		a[l].first--;
		a[r].first--;
		if(a[l].second!=a[r].second){
			ans++;
		}
		if(a[l].first==0) l++;
		if(a[r].first==0) r--;
		u++;
		//cout<<ans<<" ";
	}
	cout<<ans;
} 
