#include <bits/stdc++.h>
using namespace std;
int a[300005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1) cout<<maxn;
	else{
		sort(a+1,a+n+1,cmp);
		long long ans;
		for(int i=1;i<=m;i++){
			if(i==1) ans=a[i];
			else ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
