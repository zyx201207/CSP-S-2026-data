#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,m;
long long a[N],b[N];
long long k;
bool f(int l,int r){
	long long c=a[r]*(r-l+1);
//	cout<<r<<' '<<l<<' '<<c-b[r]+b[l-1]<<endl;
	return c-b[r]+b[l-1]<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	long long l=1,r=1;
	while(r<=n){
		while(f(l,r+1)&&r<=n){
			r++;
		}
		k=max(r-l+1,k);
		l++;
	}
	cout<<k;
	return 0;
}
