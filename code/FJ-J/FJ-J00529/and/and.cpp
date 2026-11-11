#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>=b;
}
long long n,m,i,a[10000000],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(i=1;i<=m;i++){
		ans=ans & a[i];
	}
	cout<<ans;
	return 0;
}
