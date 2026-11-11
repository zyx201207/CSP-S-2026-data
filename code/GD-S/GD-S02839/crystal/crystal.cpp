#include<iostream>
#include<cmath>
#include<cstdio>
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int n,m;
int a[N],c[N],ans=INT_MIN;
int ooo(int z){
	int cnt=0,num=0;
	for(int i=z-1;i>=1;i--){
		if(a[z]-a[i]+num>m) break;
		else{
			num+=a[z]-a[i];
			cnt++;
		}
//		cout<<num<<'\n';
	}
	return cnt;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
//		cout<<"I:"<<i<<'\n';
		ans=max(ans,ooo(i));
	}
	cout<<ans+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
} 
