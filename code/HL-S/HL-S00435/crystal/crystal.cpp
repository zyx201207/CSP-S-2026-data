#include<bits/stdc++.h>
using namespace std;
long long a[500004];
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,B=0,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int l=1;l<=n;l++){
	B=0;
	for(int i=0;i<n;i++){
	B=B+a[n-l]-a[i];
	}
	if(B<=m){
		ans=n+1-l;
		break;
	}
	}
	cout<<ans;
	return 0;
}