#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e5+10;
int n,m,ans;
int a[N];
int suming(int p){
	int sum=0;
	for(int i=0;i<p;i++){
		sum+=a[p]-a[i];
	}
	return sum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(ans=n-1;ans>=0;ans--){
		int sum=suming(ans);
		if(sum<=m){
			break;
		}
	}
	cout<<ans+1;
	return 0;
}
