#include<bits/stdc++.h>
using namespace std;
int a[500050],n,k,maxn=-10000;
int main()
{   freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==1) {
		for(int i=1;i<=n;i++) {cin>>a[i];maxn=max(maxn,a[i]);}
		cout<<maxn;
		return 0;
	}
	if(k==n){
		
		for(int i=1;i<=n;i++) {cin>>a[i];}
		int s=a[1];
		for(int i=2;i<=n;i++) {s=(s&a[i]);}
		cout<<s;return 0;
	}
	if(k==2){
		for(int i=1;i<=n;i++) {cin>>a[i];}
		sort(a+1,a+n+1);
		cout<<(a[n]&a[n-1]);return 0;
	}	
	
	return 0;
}
