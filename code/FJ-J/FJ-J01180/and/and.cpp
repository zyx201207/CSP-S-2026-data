#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long a[200005]={0};
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		a[i]=0-a[i];
	}
	sort(a+1,a+n+1);
	cout<<0-a[m];
	return 0;
}
