#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],v,l;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(l==0)l=a[i];
		else if(l&a[i]>v)v=max(v,l&a[i]),l=a[i];
	}
	cout<<v;
	return 0;
}
