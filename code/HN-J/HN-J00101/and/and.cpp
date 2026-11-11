#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	LL a[200010];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[n-1-m];
	return 0;
}

