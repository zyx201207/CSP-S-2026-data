#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[200005],ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+1+n);
	if(n/2==0){
		cout<<a[n-m];
	}else{
		cout<<a[n-m+1];
	}
	return 0;
}
