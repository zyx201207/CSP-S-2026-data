#include<bits/stdc++.h>
using namespace std;
long long a[500055],n,m,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a,a+n);
	k=a[1]-a[0];
	cout<<m/k;
}
