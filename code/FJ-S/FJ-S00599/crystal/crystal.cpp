#include <bits/stdc++.h>
using namespace std;
int n,o,p;
long long m;
long long a[500005];
long long b[500005];
int maxn=0;
int bb(int k){
	o=1;
	if(k>n) return maxn;
	for(int i=1;i<=k;i++){
		if(b[i]==b[i-1]){
			o++;		
		}
	}

	m=m-(a[k+1]-b[k])*o;
	b[k]=a[k+1];
	for(int i=k+1;i<=n;i++){
		if(b[k]==a[i]){
			o++;
		}
	}
	if(o==n){
		maxn=o;
		return maxn;
	}
	if(m<=0){
		maxn=max(o,maxn);
		m=p;
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
	}
	bb(k+1);
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	p=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	bb(1);
	cout<<maxn;
	return 0;
}
