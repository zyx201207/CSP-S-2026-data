#include<bits/stdc++.h>
using namespace std;
int zyx(int x,int y){
	return x>y;
}
int n,m,a[200005],p,q,o;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,zyx);
	p=a[1];
	q=a[m];
	o=p&q;
	cout<<o;
	return 0;
}
