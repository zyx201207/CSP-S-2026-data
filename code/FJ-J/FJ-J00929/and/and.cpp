#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],b=-100000;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b=max(b,a[i]);
	}
	cout<<b;
	return 0;
}
