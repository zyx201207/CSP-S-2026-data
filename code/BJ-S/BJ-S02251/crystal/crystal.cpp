#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[100005];
ll m;
int n;
int moni(ll x){
	int ans=0,i=1;
	ll m1=m;
	while(a[i]<x){
		if(m1>=x-a[i]){
			m1-=x-a[i];
			ans++;
		}
		else{
			break;
		}
			i++;
	}
	for(int i=1; i<=n; i++){
		if(a[i]==x){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans1=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++){
		ans1=max(ans1,moni(a[i]));
		//cout<<moni(a[i])<<" ";
	}
	cout<<ans1;
	return 0;
}
