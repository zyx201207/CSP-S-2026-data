#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000000000],p[2000000000],maxx=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;i<=n;j++){
			p[i]=a[i]&a[j];
		}
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,p[i]);
	}
	cout<<maxx;
	return 0; 
}
