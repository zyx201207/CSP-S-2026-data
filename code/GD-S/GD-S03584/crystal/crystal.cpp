#include<bits/stdc++.h>
using namespace std;
int n,l,r,mid;
long long m,a[500005],b,c,e,f[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b=a[n];
	for(int i=n;i>=1;i--){
		f[i]=b-a[i];
		f[i]+=f[i+1];
	}
	e=1;
	for(int i=2;i<=n;i++){
		l=1;
		r=i;
		while(l+5<r){
			mid=(l+r)>>1;
			if(f[mid]-f[i]-(i-mid)*(b-a[i])<=m){
				r=mid;
			}else{
				l=mid;
			}
		}
		for(int j=l;j<=r;j++){
			if(f[j]-f[i]-(i-j)*(b-a[i])<=m){
				if(i-j+1>e){
					e=i-j+1;
				}
				break;
			}
		}
	}
	cout<<e;
	return 0;
}
