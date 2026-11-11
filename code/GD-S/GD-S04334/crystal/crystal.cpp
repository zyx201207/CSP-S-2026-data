#include<bits/stdc++.h>
using namespace std;
const long long N=13e10+5;
long long a[N],pre[N];
	long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	long long maxx=-0x3f;
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<=i;j++){
			if((pre[i]-pre[j-1]+m)/(i-j+1)==a[i]){
					maxx=max(maxx,i-j+1);
			}
		}
	}
	cout<<maxx;
	return 0;
} 
