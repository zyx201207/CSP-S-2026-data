#include<bits/stdc++.h>
using namespace std;
const long long maxn=1000000;
long long a[maxn];
long long A(int p){
	long long ans=0;
	for(long long i=1;i<=p;i++){
		for(long long j=1;j<=p;j++){
			ans=max(ans,A(a[i] and a[j]));
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	A(n);
	return 0;
}
