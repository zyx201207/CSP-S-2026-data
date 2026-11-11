#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		for(int i=1;i<=n;i++){
			cout<<a[n];
			return 0;
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			cout<<a[n-1];
			return 0;
		}
	}
	cout<<n-m;
}
