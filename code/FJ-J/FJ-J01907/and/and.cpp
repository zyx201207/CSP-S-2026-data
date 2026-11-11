#include<bits/stdc++.h>
using namespace std;
int n,m,mx;
int a[200010];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	if(m==1) cout<<mx;
	return 0;
}