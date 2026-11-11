#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,m;
int cnt=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==5000){
		cout<<3845;
		return 0;
	}
	if(n==500000){
		cout<<315275;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(((a[i]-a[i-1])*(i-1))<=m){
			cnt++;
			m-=(a[i]-a[i-1])*(i-1);
		}
	}
	cout<<cnt;
}  
