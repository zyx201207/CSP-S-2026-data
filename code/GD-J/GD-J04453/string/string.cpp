#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<char> v; 
ll a[200010];
char c[200010];
ll n,sum,ans;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	bool f=1;
	for(int i=2;i<=n;i++){
		if(c[i]!=c[i-1]){
			f=0;
			break;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	if(sum>1e9){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			v.push_back(c[i]);
		}
	}
	ll l=0,r=sum-1;
	while(l<=r){
		if(v[l]!=v[r]){
			ans++;
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
} 

