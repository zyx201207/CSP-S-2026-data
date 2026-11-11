#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[1000000],h;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	h=a[0];
	for(int i=1;i<m;i++){
		h=h&a[i];
	}
	cout<<h;
	return 0;
}
