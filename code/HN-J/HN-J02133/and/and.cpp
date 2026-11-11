#include <bits/stdc++.h>
using namespace std;
int n,b,a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>b;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort (a,a+n);
	for (int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<a[n-2];
}
