#include<bits/stdc++.h>
using namespace std;

long long n,m,ans,a[200100];

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(long long i=1;i<=m;i++){
		ans=ans&a[i];
	}
	if(ans) cout<<ans;
	else cout<<a[m];
	return 0;
}
