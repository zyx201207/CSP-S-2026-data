#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000086];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0){
		cout<<a[n/2];
	}else{
		cout<<a[n/2+1];
	}
	return 0;
}
