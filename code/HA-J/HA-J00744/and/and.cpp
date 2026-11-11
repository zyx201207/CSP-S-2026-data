#include<bits/stdc++.h>
using namespace std;
int n,m,a[2020],zd=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zd=max(zd,a[i]);
	}
	cout<<zd;
	return 0;
}

