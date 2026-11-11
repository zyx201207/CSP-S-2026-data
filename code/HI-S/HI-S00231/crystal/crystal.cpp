#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,b=1;
	cin>>n>>m;
	int a[500001]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])*b<=m){
			m-=(a[i]-a[i-1])*b;
			b++;
		}
	}
	cout<<b;
	return 0;
}
