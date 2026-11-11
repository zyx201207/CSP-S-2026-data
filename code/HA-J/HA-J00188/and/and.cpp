#include<bits/stdc++.h>
using namespace std;
long long n,m,p=0,h=0,g=0;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		h=max(a[i],h);
	}
	if(m==1){
		cout<<h;
		return 0;
	}
	long long g=0;
	if(m==2){
		sort(a+1,a+n+1);
		for(long long i=n;i>=1;i--){
			long long k=a[i]&a[i-1];
			g=max(g,k);
		}
		cout<<g;
		return 0;
	}
	sort(a+1,a+n+1);
	long long k=a[n]&a[n];
	for(long long i=n-1;i>=1;i--){
		k=k&a[i];
		p++;
		if(p==m-1){
			break;
		}
	}
	cout<<k;
	return 0;

}
