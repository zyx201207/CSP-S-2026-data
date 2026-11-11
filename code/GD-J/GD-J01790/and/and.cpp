#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],l,f[50];
int sz(int n){
	for(int i=0;i<=30;i++){
		if(n<f[i]) return f[i]-n+i*(-i);
	}
}
bool cmp(long long x,long long y){
	return sz(x)<sz(y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	f[0]=1;
	for(int i=1;i<=30;i++) f[i]=f[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	l=a[1];
	for(int i=2;i<=m;i++)
		l&=a[i];
	cout<<l;
	return 0;
}
