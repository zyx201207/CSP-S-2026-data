#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
priority_queue<int> g;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	cout<<n; 
}
