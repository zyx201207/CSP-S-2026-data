#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,maxx=0,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			if(a[i]&a[j]>maxx) maxx=a[i]&a[j];
		}
	}
	cout<<maxx;
	return 0;
}
