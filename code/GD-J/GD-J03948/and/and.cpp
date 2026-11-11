#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[200010],ma;
bool cmp(int x,int y){
	return y<x;
}
void pd(int x,int y){
	if(x==m){
		sort(b+1,b+1+m,cmp);
		for(int i=1;i<m;i++){
			b[i+1]=b[i+1]&b[i];
		}
		ma=max(b[m],ma);
		return ;
	}
	for(int i=y;i<=n;i++){
		b[x+1]=a[i];
		pd(x+1,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	pd(0,1);
	cout<<ma;
	return 0;
}
