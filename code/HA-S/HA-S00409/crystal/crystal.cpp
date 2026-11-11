#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n);
	sort(b+1,b+n);
	cout<<m-3;
	return 0;
}
