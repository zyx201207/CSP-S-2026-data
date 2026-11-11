#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
bool arr1(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			return false;
		}
	}
	return true;
}
bool arr2(){
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		int ans=0;
		map<int,int> mp;
		for(int i=1;i<=n;i++){
			mp[a[i]]++;
			if(mp[a[i]]>=2) ans=max(ans,mp[a[i]]);
		}
		cout<<ans;
	}else if(arr1()){
		int ans=1;
		for(int i=1;i<=n;i++){
			if(m-i<0) break;
			m-=i;
			ans++;
		}
		cout<<max(m+1,ans);
	}else if(arr2()){
		int ans=1,c=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(m-i*c<0) break;
			m-=i*c;
			ans++;
		}
		cout<<ans;
	}
	return 0;
}
