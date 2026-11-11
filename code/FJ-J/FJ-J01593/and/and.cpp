#include<bits/stdc++.h>
using namespace std;
int a[200001];
void csh(){

}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long ans,n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n+1);
	ans=a[n];	
	for(int i=n-1;i>=n-m+1;i--) ans=(ans&a[i]);
	cout<<ans;
	return 0;
}
