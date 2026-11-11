#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010]={};
int s[200010]={};
int maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i-1]&a[i];
		maxx=max(maxx,s[i]);
	}
	cout<<maxx;
	return 0;
}
