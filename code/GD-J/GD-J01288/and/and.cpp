#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n,a[200005];
bool issprime(int x){
	if(x<2)return 0;
	for(int i=3;i<=x;i+=2){
		if(x%i==0)return 0;
	}
	return 1;
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(issprime(n))cout<<n-m;
	else{
		sort(a+1,a+n+1,cmp);
		int ans=a[m];
		cout<<ans;
	}
	return 0;
}

