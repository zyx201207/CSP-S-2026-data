#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,maxv,minv;
long long a[200010],f[200010];
int main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxv=max(maxv,a[i]);
		minv=min(minv,a[i]);
	}
	if(m==n-1){
		for(int i=2;i<=n;i++){
			if(a[i]==minv){
				a[i]&=0;
			}
			else a[i]&=a[i-1];
		}
		cout<<a[n];
		return 0;
	}
	if(m==1){
		cout<<maxv-1;
		return 0;
	}
	if(n==m){
		for(int i=2;i<=n;i++){
			a[i]&=a[i-1];
		}
		cout<<a[n];
		return 0;
	}
	return 0;
}
