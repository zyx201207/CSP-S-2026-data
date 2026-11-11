#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k; 
	for (int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for (int i=2;i<=k;++i){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
