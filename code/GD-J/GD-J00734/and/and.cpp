#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m!=1) cout<<a[n-1];
	else{
		sort(a,a+n);
		cout<<a[n-1];
	}
	return 0;
}
