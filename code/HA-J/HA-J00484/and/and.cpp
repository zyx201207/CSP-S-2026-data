#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL N=2e5+10;
LL n,m;
LL a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[(n+1)/2-1];
	return 0;
}
