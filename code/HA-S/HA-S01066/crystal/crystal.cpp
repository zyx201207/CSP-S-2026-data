#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000000];
long long w=0;
long long l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long j=n;j>=1;j--){
		if(j<=w) break;			
		long long x=m;
		long long v=1;
		for(long long b=j-1;b>=1;b--){
			if(x<a[j]-a[b]) break;
			v+=1;
			x=x-(a[j]-a[b]);
		}
		w=max(w,v);
	}
	cout<<w;
}
