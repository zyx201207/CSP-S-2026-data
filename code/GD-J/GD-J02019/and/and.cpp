#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx,id,x;
bool f[200005];
void tle(long long n,long long m){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>mx){
			id=i;
			mx=a[i];
		}
	}
	f[id]=1;
	while(m--){
		x=mx;
		f[id]=1;
		mx=-1;
		for(int i=1;i<=n;i++){
			if(f[i])continue;
			if((x&a[i])>mx){
				id=i;
				mx=(x&a[i]);
			}
		}
	}
	cout<<x;
}
void nm(long long n,long long m){
	cin>>mx;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		mx=(mx&a[i]);
	}
	cout<<mx;
}
void A(long long n,long long m){
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n==m)nm(n,m);
	else if(n*m<=1e9)tle(n,m);
	else A(n,m);
	return 0;
}
