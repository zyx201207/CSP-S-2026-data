#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005]={0},b[200005]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=n;i>=0;i--){
		b[n-i]+=a[i];
	}
	cout<<b[n-m];
	return 0;
	
}
