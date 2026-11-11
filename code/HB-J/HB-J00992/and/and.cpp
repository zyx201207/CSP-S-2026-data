#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<long long>());
	cout<<a[m-1];
	return 0;
}
